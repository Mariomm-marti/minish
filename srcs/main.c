/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 03:55:44 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <piper.h>
#include <utils.h>
#include <command.h>
#include <libft.h>
#include <signals.h>

int	main(void)
{
	t_command	*commands;
	char		*line;
	int			status;
	
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	commands = NULL;
	utils_update_var("?", "0");
	while (true)
	{
		line = readline("miniSH$ ");
		if (!line)
			break ;
		if (!*utils_strstop(line, utils_validator_isspace))
			continue ;
		if (!utils_check_quotes(line))
		{
			printf("miniSH: quotes error\n");
			utils_update_var("?", "127");
			continue ;
		}
		add_history(line);
		commands = parser_parse(line);
		free(line);
		if (!utils_check_pipeline(commands))
		{
			printf("miniSH: unknown command\n");
			utils_update_var("?", "127");
			parser_free(commands);
			continue ;
		}
		exec_command(commands);
		while (wait(&status) > 0)
			;
		line = ft_itoa(status);
		utils_update_var("?", line);
		free(line);
		parser_free(commands);
	}
}
