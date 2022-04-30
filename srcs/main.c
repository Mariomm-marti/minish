/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/04/30 12:16:57 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <piper.h>
#include <utils.h>
#include <command.h>
#include <libft.h>
#include <signals.h>

static bool	main_preprocess(char *line, t_command **cmds)
{
	if (!*utils_strstop(line, utils_validator_isspace))
	{
		free(line);
		return (true);
	}
	if (!utils_check_quotes(line))
	{
		printf("miniSH: quotes error\n");
		utils_update_var("?", "127");
		free(line);
		return (true);
	}
	add_history(line);
	*cmds = parser_parse(line);
	free(line);
	if (!utils_check_pipeline(*cmds))
	{
		printf("miniSH: unknown command\n");
		utils_update_var("?", "127");
		parser_free(*cmds);
		*cmds = NULL;
		return (true);
	}
	return (false);
}

int	main(void)
{
	t_command	*commands;
	char		*line;
	int			status;

	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	commands = NULL;
	while (true)
	{
		line = readline("miniSH$ ");
		if (!line)
			break ;
		if (main_preprocess(line, &commands))
			continue ;
		exec_command(commands);
		while (wait(&status) > 0)
			;
		if (status > 255)
			status = status - 255;
		line = ft_itoa(status);
		utils_update_var("?", line);
		free(line);
		parser_free(commands);
	}
}
