/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:34:44 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 19:18:02 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>

int	seek_builtin(char *cmd)
{
	size_t	i;
	const builtins[8] = {"echo", "export", "unset", "cd", "pwd", "exit", "env", NULL};

	if (*cmd == '/')
		return (-1);
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp(cmd, builtins[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	execute(t_command *cmd, int p[2])
{
	pid_t		pid;
	char		blt;
	extern char	**environ;
	const t_builtins	table[8] = {ft_echo, ft_export, ft_unset, ft_cd, ft_pwd, ft_exit, ft_env, NULL};


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
	blt = seek_builtin(cmd);
	if (blt >= 0)
		table[blt](cmd->argv, cmd->fdin, cmd->fdout);
	else
		execve(cmd->cmd, cmd->argv, environ);
}

void	exec_command(t_command *cmd)
{
	int			p[2];
	t_command	*cmd1;
	t_command	*cmd2;

	cmd1 = cmd;
	cmd2 = cmd->next;
	while (cmd2)
	{
		pipe(p);
		if (cmd->fdout == 1)
			cmd1->fdout = p[1];
		if (cmd->fdin == 0)
			cmd2->fdin = p[0];
		execute(cmd1, p);
		close(p[1]);
		if (cmd1->fdin)
			close(cmd1->fdin);
		cmd1 = cmd1->next;
		cmd2 = cmd2->next;
	}
	execute(cmd1, p);
	close(cmd1->fdin);
}
