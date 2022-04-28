/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:13:16 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 00:41:26 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>
#include <utils.h>
#include <command.h>
#include <stdio.h>

void	print_all(t_command const *command)
{
	size_t	current_arg;

	if (!command)
		return ;
	current_arg = 0;
	printf("command:\n");
	printf("cmd    :%s\n", command->cmd);
	printf("argc   :%d\n", command->argc);
	printf("argv-p :%p\n", command->argv);
	printf("argv   :\n");
	while (command->argv && command->argv[current_arg])
	{
		printf("%s\n", command->argv[current_arg]);
		current_arg++;
	}
	printf("fdin   :%d\n", command->fdin);
	printf("fdout  :%d\n\n", command->fdout);
	print_all(command->next);
}

int	main(void)
{
	t_command	*cmd;
	char		*line;

	utils_update_var("?", "0");
	line = readline("CMD: ");
	cmd = parser_parse(line);
	print_all(cmd);
	free(line);
	parser_free(cmd);
}
