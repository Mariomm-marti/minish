/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:53:34 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/16 21:39:34 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPER_H
# define PIPER_H

# include <sys/types.h>
# include <command.h>

typedef struct s_tops {
	pid_t	pds_list[200];
	size_t	index_pd;
}				t_tops;

t_tops	pds;
/*
**	EXEC COMMAND
**	Execute the commads with their arguments and to alias the fd's as 0 or 1
**	according the situation.
*/

ssize_t	execute(t_command *cmd, int p[2], char last);

/*
**	PIPER
**	Create a process for each pipe and assign fd's (input and output) for
**	each command.
*/
size_t	exec_command(t_command *cmd);

int		seek_builtin(char *cmd);

#endif
