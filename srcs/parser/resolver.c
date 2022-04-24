/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:50:41 by vim               #+#    #+#             */
/*   Updated: 2022/04/24 19:44:31 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <stdbool.h>
#include <libft.h>
#include <stdlib.h>
#include <utils.h>
#include <unistd.h>

static char	*create_fullpath(char const *folder, char const *binary)
{
	char	*str;

	str = ft_strdup(folder);
	str = utils_strpush(str, '/');
	while (*binary)
	{
		str = utils_strpush(str, *binary);
		binary++;
	}
	return (str);
}

static char	*resolve_path(char const *str)
{
	char	**folders;
	char	*fullpath;
	size_t	counter;
	bool	found;

	folders = ft_split(getenv("PATH"), ':');
	if (!folders)
		return (NULL);
	counter = 0;
	found = false;
	while (*(folders + counter))
	{
		fullpath = create_fullpath(*(folders + counter), str);
		if (access(fullpath, F_OK) == 0)
		{
			found = true;
			break ;
		}
		free(fullpath);
		counter++;
	}
	ft_split_free(folders);
	if (found == false)
		return (NULL);
	return (fullpath);
}

void	command_resolve_path(t_command *cmd)
{
	char	*cmdstr;

	cmdstr = *(cmd->argv);
	free(cmd->cmd);
	cmd->cmd = NULL;
	if (!cmdstr)
		return ;
	if (*cmdstr == '/')
	{
		cmd->cmd = ft_strdup(cmdstr);
		return ;
	}
	cmd->cmd = resolve_path(cmdstr);
}
