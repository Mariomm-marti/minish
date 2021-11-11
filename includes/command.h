/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 04:28:52 by vim               #+#    #+#             */
/*   Updated: 2021/11/10 07:12:54 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_command
{
	char				*cmd;
	int					argc;
	char				*tempargs;
	char				**argv;
	int					fdin;
	int					fdout;
	struct s_command	*next;
}	t_command;

typedef void	(*t_command_iter)(t_command *);

/*
** Generates the linked list t_command *, assigning to t_command->cmd
** the resulting string.
** It requires a second layer of processing, to determine the real command,
** the arguments, etc.
*/
t_command	*command_splitter(char const *line);

/*
** An util function used to iterate the linked list of t_command *
** passing in an iterator.
*/
void		command_iterator(t_command *cmd, t_command_iter const iterator);

/*
** Second layer, splits the command and the arguments without properly removing
** quotes or determining the real command using PATH.
** Everything that is not a command will be placed under argv as a simple
** string.
** Requires a second layer to determine the command and the arguments.
*/
void		command_finder(t_command *cmd);

#endif
