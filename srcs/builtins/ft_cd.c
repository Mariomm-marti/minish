/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/08 00:06:53 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <utils.h>
#include <libft.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	change_pwd(char *previous_dir, char *new_pwd)
{
	utils_update_var("OLDPWD", previous_dir);
	utils_update_var("PWD", new_pwd);
	return (0);
}

static ssize_t	which_action(char *path, char *home, char *previous_dir,
		char *actual_dir)
{
	if (!*path)
	{
		home = getenv("HOME");
		if (!home)
			return (-1);
		chdir(home);
		return (change_pwd(previous_dir, home));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = getenv("OLDPWD");
		printf("%s", path);
	}
	if (!chdir(path))
	{
		actual_dir = getcwd(NULL, 0);
		return (change_pwd(previous_dir, actual_dir));
	}
	return (-1);
}

ssize_t	ft_cd(char const **argv, int fdin, int fdout)
{
	char		*path;
	char		*home;
	char		*previous_dir;
	char		*actual_dir;
	ssize_t		ret;

	(void)fdin;
	(void)fdout;
	home = NULL;
	actual_dir = NULL;
	path = ft_strdup(*(argv + 1));
	previous_dir = getenv("PWD");
	ret = which_action(path, home, previous_dir, actual_dir);
	free(path);
	return (ret);
}
