/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 04:28:52 by vim               #+#    #+#             */
/*   Updated: 2022/04/03 03:07:45 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_command
{
	char				*cmd;
	int					argc;
	char				**argv;
	int					fdin;
	int					fdout;
	struct s_command	*next;
}	t_command;

typedef void	(*t_command_iter)(t_command *);

t_command	*parser_parse(char *line);
void		parser_free(t_command *commands);

void		command_iterator(t_command *cmd, t_command_iter const iterator);

t_command	*command_splitter(char const *line);
void		command_replace_vars(t_command *cmd);
void		command_redirections(t_command *cmd);
void		command_do_arguments(t_command *cmd);
void		command_resolve_path(t_command *cmd);

#endif
