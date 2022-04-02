/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:15:08 by vim               #+#    #+#             */
/*   Updated: 2022/04/03 01:14:10 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

t_command	*parser_parse(char *line)
{
	t_command	*commands;

	commands = command_splitter(line);
	command_iterator(commands, command_replace_vars);
	command_iterator(commands, command_redirections);
	command_iterator(commands, command_do_arguments);
	return (commands);
}

void	parser_free(t_command *commands)
{
	if (!commands)
		return ;
	parser_free(commands->next);
	free(commands->cmd);
	ft_split_free(commands->argv);
	if (commands->fdin != 0)
		close(commands->fdin);
	if (commands->fdout != 0)
		close(commands->fdout);
	free(commands);
}
