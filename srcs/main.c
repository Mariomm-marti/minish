/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/04/07 23:52:46 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <piper.h>
#include <utils.h>
#include <command.h>

int		main(void)
{
	t_command	*commands;
	char		*line;

	commands = NULL;
	while (true)
	{
		show_prompt();
		line = readline("");
		add_history(line);
		commands = parser_parse(line);
		free(line);
		exec_command(commands);
		parser_free(commands);
	}
}
