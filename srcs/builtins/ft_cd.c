/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/15 20:24:39 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

static int	change_pwd(char *previous_dir, char *new_pwd)
{
	utils_change_var("OLDPWD", previous_dir);
	utils_change_var("PWD", new_pwd);
	return (0);
}

int	ft_cd(const char *path)
{
	char		*home;
	char		*previous_dir;
	char		*actual_dir;

	previous_dir = getenv("PWD");
	if (!*path)
	{
		home = getenv("HOME");
		if (!home)
			return (-1);
		chdir(home);
		return (change_pwd(previous_dir, home));
	}
	if (!chdir(path))
	{
		actual_dir = getcwd(NULL, 0);
		return (change_pwd(previous_dir, actual_dir));
	}
	errno = ENOENT;
	return (-1);
}
