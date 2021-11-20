/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 18:38:10 by mortega-         ###   ########.fr       */
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

static void	which_action(char *path, char *home, char *previous_dir, char *actual_dir)
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

	path = ft_strdup(*argv);
	previous_dir = getenv("PWD");
	ret = which_action(path, home, previous_dir, actual_dir);
	free(path);
	return (ret);
}
