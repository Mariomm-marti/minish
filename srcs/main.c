/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/04/25 18:39:12 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <piper.h>
#include <utils.h>
#include <command.h>
#include <signals.h>
#include <unistd.h>	/////

int		main(void)
{
	t_command	*commands;
	char		*line;

	commands = NULL;
	while (true)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		//printf("Prompt: %s\n", show_prompt());
		printf("Y peto\n");
		line = readline("");
		printf("|%s|\n", line);
		add_history(line);
		commands = parser_parse(line);
		free(line);
		exec_command(commands);
		while (wait(NULL) > 0)
			;
		//parser_free(commands);
	}
}
