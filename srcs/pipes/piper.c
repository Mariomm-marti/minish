/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:34:44 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/25 18:43:18 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <piper.h>
#include <unistd.h>
#include <builtins.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h> //////

int	seek_builtin(char *cmd)
{
	size_t		i;
	const char	*builtins[7] = {"echo", "export", "unset", "cd", "pwd",
		"exit", "env"};

	//if (*cmd == '/')
	//	return (-1);
	if (!cmd)
		return -1;
	char	*s = ft_strrchr(cmd, '/') + 1;
	//printf("S = %s\n", s);
	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(s, builtins[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	execute(t_command *cmd, int p[2])
{
	pid_t				pid;
	int					blt;
	extern char			**environ;
	const t_builtin		table[7] = {ft_echo, ft_export, ft_unset, ft_cd,
		ft_pwd, ft_exit, ft_env};

	blt = seek_builtin(cmd->cmd);
	printf("blt = %d\n", blt);
	if (blt < 0)
	{
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
	}
	if (blt >= 0)
		table[blt]((const char **)cmd->argv, cmd->fdin, cmd->fdout);
	else
		execve(cmd->cmd, cmd->argv, environ);
}

void	exec_command(t_command *cmd)
{
	int			p[2];
	t_command	*cmd1;
	t_command	*cmd2;

	cmd1 = cmd;
	printf("Cmd = %s\n", cmd->cmd);
	cmd2 = cmd->next;
	cmd1->fdin = 0; //
	cmd1->fdout = 1; //
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
	execute(cmd1, p);
	if (cmd1->fdin)
		close(cmd1->fdin);
}
