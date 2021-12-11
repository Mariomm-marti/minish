/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 04:28:52 by vim               #+#    #+#             */
/*   Updated: 2021/12/11 20:52:03 by vim              ###   ########.fr       */
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

t_command	*command_splitter(char const *line);

void		command_iterator(t_command *cmd, t_command_iter const iterator);

void		command_replace_vars(t_command *cmd);
void		command_finder(t_command *cmd);

#endif
