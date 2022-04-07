/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 04:56:28 by vim               #+#    #+#             */
/*   Updated: 2022/04/03 01:04:36 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <libft.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>

static ssize_t	command_find_pipe(char const *line, ssize_t index)
{
	bool	simple_lock;
	bool	double_lock;

	simple_lock = false;
	double_lock = false;
	while (*(line + index))
	{
		if (*(line + index) == '\'' && !double_lock)
			simple_lock = !simple_lock;
		if (*(line + index) == '"' && !simple_lock)
			double_lock = !double_lock;
		if (*(line + index) == '|' && !simple_lock && !double_lock)
			return (index);
		index++;
	}
	return (-1);
}

static void	command_push(t_command **cmd, char *cmdstr)
{
	t_command	*newcmd;
	t_command	*head;

	newcmd = malloc(sizeof(t_command));
	if (!newcmd)
		return ;
	ft_bzero(newcmd, sizeof(t_command));
	newcmd->cmd = cmdstr;
	if (*cmd == NULL)
	{
		*cmd = newcmd;
		return ;
	}
	newcmd->argv = malloc(sizeof(char *));
	*(newcmd->argv) = NULL;
	head = *cmd;
	while (head->next != NULL)
		head = head->next;
	head->next = newcmd;
}

t_command	*command_splitter(char const *line)
{
	t_command	*cmd;
	ssize_t		pipe;
	ssize_t		prev_pipe;

	if (!line)
		return (NULL);
	cmd = NULL;
	prev_pipe = 0;
	pipe = command_find_pipe(line, prev_pipe);
	while (pipe != -1)
	{
		command_push(&cmd, ft_substr(line, prev_pipe, pipe - prev_pipe));
		prev_pipe = pipe + 1;
		pipe = command_find_pipe(line, prev_pipe);
	}
	command_push(&cmd, ft_substr(line, prev_pipe, ft_strlen(line)));
	return (cmd);
}
