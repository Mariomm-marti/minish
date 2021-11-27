/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:53:34 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/27 18:22:05 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPER_H
# define PIPER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
**	EXEC COMMAND
**	Execute the commads with their arguments and to alias the fd's as 0 or 1
**	according the situation.
*/

void	execute(t_command *cmd, int p[2]);

/*
**	PIPER
**	Create a process for each pipe and assign fd's (input and output) for
**	each command.
*/

void	exec_command(t_command *cmd);


#endif
