/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:48:16 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/14 21:49:19 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

ssize_t	ft_pwd(const char **argv, int fdin, int fdout)
{
	char		*buf;
	const char	*param;

	(void)fdin;
	param = *(argv + 1);
	if (param && *param == '-' && *(param + 1) != '\0')
		return (1);
	buf = getcwd(NULL, 0);
	if (access(buf, F_OK))
	{
		free(buf);
		printf("directory cannot be accessed\n");
		return (1);
	}
	write(fdout, buf, ft_strlen(buf));
	write(fdout, "\n", 1);
	free(buf);
	return (0);
}
