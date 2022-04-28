/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 01:45:27 by mmartin-         ###   ########.fr       */
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

int		main(void)
{
	t_command	*commands;
	char		*line;
	
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	commands = NULL;
	utils_update_var("?", "0");
	while (true)
	{
		line = readline("miniSH$ ");
		rl_redisplay();
		if (EOF && !line)
			break ;
		add_history(line);
		commands = parser_parse(line);
		free(line);
		if (!utils_validator_command_line(commands))
		{
			printf("miniSH: command not found\n");
			utils_update_var("?", "127");
			parser_free(commands);
			continue ;
		}
		exec_command(commands);
		//TODO
		utils_update_var("?", "0");
		while (wait(NULL) > 0)
			;
		parser_free(commands);
	}
	// return (el error);
}
