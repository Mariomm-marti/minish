/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:34:44 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 02:20:37 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <piper.h>
#include <unistd.h>
#include <builtins.h>
#include <libft.h>
#include <stdlib.h>

int	seek_builtin(char *cmd)
{
	size_t		i;
	const char	*builtins[7] = {"echo", "export", "unset", "cd", "pwd",
		"exit", "env"};

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(cmd, builtins[i]))
			return (i);
		i++;
	}
	return (-1);
}

ssize_t execute(t_command *cmd, int p[2], char last)
{
	pid_t				pid;
	int					blt;
	extern char			**environ;
	const t_builtin		table[7] = {ft_echo, ft_export, ft_unset, ft_cd,
		ft_pwd, ft_exit, ft_env};

	blt = seek_builtin(*(cmd->argv));
	if (blt < 0)
	{
		pid = fork();
		if (pid != 0)
			return (0);
		if (last == 0)
			close(p[0]);
		dup2(cmd->fdin, 0);
		close(cmd->fdin);
		dup2(cmd->fdout, 1);
		if (cmd->fdout != 1)
			close(cmd->fdout);
	}
	if (blt >= 0)
		return (table[blt]((const char **)cmd->argv, cmd->fdin, cmd->fdout));
	else
		return (execve(cmd->cmd, cmd->argv, environ));
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
		cmd1->fdout = p[1];
		cmd2->fdin = p[0];
		if (execute(cmd1, p, 0) < 0)
			;
		close(p[1]);
		if (cmd1->fdin)
			close(cmd1->fdin);
		cmd1 = cmd1->next;
		cmd2 = cmd2->next;
	}
	if (execute(cmd1, p, 1) < 0)
		printf("%s: not working", cmd1->cmd);
	if (cmd1->fdin)
		close(cmd1->fdin);
}
