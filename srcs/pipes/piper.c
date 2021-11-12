/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:34:44 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 18:42:43 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>

void	execute(t_command *cmd, int p[2])
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return ;
	if (cmd->fdout != 1)
		close(p[0]);
	dup2(cmd->fdin, 0);
	close(cmd->fdin);
	dup2(cmd->fdout, 1);
	if (cmd->fdout != 1)
		close(cmd->fdout);
	execve(cmd->cmd, cmd->argv, NULL);
}

void	exec_command(t_command *cmd)
{
	int			p[2];
	t_command	*cmd1;
	t_command	*cmd2;

	cmd1 = cmd;
	cmd2 = cmd->next;
	cmd1->fdin = 0;
	while (cmd2)
	{
		pipe(p);
		cmd1->fdout = p[1];
		cmd2->fdin = p[0];
		execute(cmd1, p);
		close(p[1]);
		if (cmd1->fdin)
			close(cmd1->fdin);
		cmd1 = cmd1->next;
		cmd2 = cmd2->next;
	}
	cmd1->fdout = 1;
	execute(cmd1, p);
	close(cmd1->fdin);
}
