/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/17 18:27:42 by test             ###   ########.fr       */
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
	if (get_env("OLDPWD"))
		utils_update_var("OLDPWD", previous_dir);
	if (get_env("PWD"))
		utils_update_var("PWD", new_pwd);
	else
		utils_update_var("OLDPWD", "");
	return (0);
}

static ssize_t	which_action(char *path, char *home, char *previous_dir,
		char *actual_dir)
{
	if (!path)
	{
		home = get_env("HOME");
		if (!home)
			return (1);
		chdir(home);
		return (change_pwd(previous_dir, home));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = get_env("OLDPWD");
		if (!path)
			return (-1);
		printf("%s\n", path);
	}
	if (!chdir(path))
	{
		actual_dir = getcwd(NULL, 0);
		change_pwd(previous_dir, actual_dir);
		free(actual_dir);
		return (0);
	}
	return (1);
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
	if (!(*(argv + 1)))
		path = NULL;
	else
		path = ft_strdup(*(argv + 1));
	previous_dir = get_env("PWD");
	ret = which_action(path, home, previous_dir, actual_dir);
	free(path);
	return (ret);
}
