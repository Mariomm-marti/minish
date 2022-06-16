/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:13:48 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/16 18:11:48 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <unistd.h>
#include <stdbool.h>
#include <utils.h>

static bool	jump_dollar(char *var, size_t *j)
{
	if (ft_strncmp(var, "?", 1) == 0)
	{
		(*j)++;
		return (true);
	}
	return (false);
}

ssize_t	ft_env(char const **argv, int fdin, int fdout)
{
	size_t		i;
	size_t		j;

	(void)fdin;
	if (*(argv + 1))
		return (127);
	j = 0;
	while (*(environ_heap + j))
	{
		if (jump_dollar(*(environ_heap + j), &j))
			continue ;
		i = -1;
		while (*(*environ_heap + ++i))
		{
			if (*(*environ_heap + i) == '=')
			{
				write(fdout, *(environ_heap + j),
						ft_strlen(*(environ_heap + j)));
				write(fdout, "\n", 1);
			}
		}
		j++;
	}
	return (0);
}
