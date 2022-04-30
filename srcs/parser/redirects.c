/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:17:57 by vim               #+#    #+#             */
/*   Updated: 2022/04/30 10:42:31 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <command.h>
#include <utils.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>

static char	*get_filename(char *cmd, char **endp)
{
	char	*finalstr;
	char	lock;

	lock = 0;
	finalstr = ft_strdup("");
	if (*cmd == '<' || *cmd == '>')
		cmd++;
	while (utils_validator_isspace(*cmd))
		cmd++;
	while (*cmd && !(lock == 0 && utils_validator_isspace(*cmd)))
	{
		if (lock == *cmd)
			lock = 0;
		else if ((*cmd == '"' || *cmd == '\'') && lock == 0)
			lock = *cmd;
		else
			finalstr = utils_strpush(finalstr, *cmd);
		cmd++;
	}
	*endp = cmd;
	return (finalstr);
}

static void	do_heredoc(int const fd, char const *end)
{
	char	*line;

	line = readline(">");
	while (line && ft_strcmp(line, end))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(">");
	}
	free(line);
}

static char	*process_redirect(char *cmd, int *fdin, int *fdout)
{
	char		*endp;
	char const	*filename = get_filename(cmd + 1, &endp);

	if (*cmd == '>' && *(cmd + 1) == '>')
		*fdout = open(filename,
				O_WRONLY | O_CREAT | O_SYMLINK | O_APPEND, 0644);
	else if (*cmd == '>')
		*fdout = open(filename, O_WRONLY | O_CREAT | O_SYMLINK | O_TRUNC, 0644);
	else if (*cmd == '<' && *(cmd + 1) == '<')
	{
		*fdin = open("/tmp/_tmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
				0644);
		do_heredoc(*fdin, filename);
		close(*fdin);
		*fdin = open("/tmp/_tmp", O_RDONLY | O_CREAT | O_SYMLINK, 0644);
	}
	else if (*cmd == '<')
		*fdin = open(filename, O_RDONLY | O_CREAT | O_SYMLINK, 0644);
	free((char *)filename);
	return (endp - 1);
}

void	command_redirections(t_command *cmd)
{
	char	*cmdstr;
	char	*finalstr;
	char	lock;

	cmdstr = cmd->cmd;
	finalstr = ft_strdup("");
	lock = 0;
	while (*cmdstr)
	{
		if (lock == *cmdstr)
			lock = 0;
		else if ((*cmdstr == '"' || *cmdstr == '\'') && lock == 0)
			lock = *cmdstr;
		if ((*cmdstr == '>' || *cmdstr == '<') && lock == 0)
			cmdstr = process_redirect(cmdstr, &(cmd->fdin), &(cmd->fdout));
		else
			finalstr = utils_strpush(finalstr, *cmdstr);
		cmdstr++;
	}
	free(cmd->cmd);
	cmd->cmd = finalstr;
}
