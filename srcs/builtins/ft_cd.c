/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/25 18:54:08 by mortega-         ###   ########.fr       */
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
	printf("Puto inutil\n");
	utils_update_var("PWD", new_pwd);
	return (0);
}

static ssize_t	which_action(char *path, char *home, char *previous_dir,
		char *actual_dir)
{
	if (!path)
	{
		printf("Aqui entramos>bien\n");
		home = getenv("HOME");
		printf("home: |%s|\n", home);
		if (!home)
			return (-1);
		chdir(home);
		printf("Aqui guay\n");
		return (change_pwd(previous_dir, home));
	}
	if (!ft_strcmp(path, "-"))
	{
		path = getenv("OLDPWD");
		if (!path)
			return (-1);
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
	printf("Aqui llega\n");
	printf("argv1: |%s|\n", *(argv + 1));
	if (!(*(argv + 1)))
		path = NULL;
	else
		path = ft_strdup(*(argv + 1));
	printf("paht: |%s|\n", path);
	previous_dir = getenv("PWD");
	printf("dir: |%s|\n", previous_dir);
	ret = which_action(path, home, previous_dir, actual_dir);
	free(path);
	return (ret);
}
