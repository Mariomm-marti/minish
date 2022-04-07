/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:13:48 by mortega-          #+#    #+#             */
/*   Updated: 2022/01/15 16:59:48 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <unistd.h>

ssize_t	ft_env(char **argv, int fdin, int fdout)
{
	extern char	**environ;
	size_t		i;

	if (argv + 1)
		return (127);
	while (*environ)
	{
		i = 0;
		while (*(*environ + i))
		{
			if (*(*environ + i) == '=')
			{
				write(fdout, *environ, ft_strlen(*environ));
				write(fdout, "\n", 1);
			}
			i++;
		}
		environ++;
	}
	return (0);
}
