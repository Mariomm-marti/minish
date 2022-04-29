/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:13:48 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 04:55:03 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <unistd.h>

#include <stdio.h>////

ssize_t	ft_env(char const **argv, int fdin, int fdout)
{
	extern char	**environ;
	size_t		i;
	size_t		j;

	(void)fdin;
	if (*(argv + 1))
		return (127);
	j = 0;
	while (*(environ + j))
	{
		i = 0;
		if (ft_strncmp(*(environ + j), "?", 1) == 0)
		{
			j++;
			continue ;
		}
		while (*(*environ + i))
		{
			if (*(*environ + i) == '=')
			{
				write(fdout, *(environ + j), ft_strlen(*(environ + j)));
				write(fdout, "\n", 1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
