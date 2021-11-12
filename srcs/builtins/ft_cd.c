/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:49:50 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 13:33:27 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_cd(const char *path)
{
	char		*home;
	char		*previous_dir;
	char		*actual_dir;
	extern char	**environ;

	home = getenv("HOME");
	previous_dir = getenv("PWD");
	if (!*path)
	{
		chdir(home);
		utils_change_var("OLDPWD", previous_dir);
		utils_change_var("PWD", home);
		return (0);
	}
	if (!chdir(path))
	{
		actual_dir = getcwd(NULL, 0);
		utils_change_var("OLDPWD", previous_dir);
		utils_change_var("PWD", actual_dir);
		return (0);
	}
	errno = ENOENT;
	return (-1);
}
