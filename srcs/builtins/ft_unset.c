/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:20 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/18 19:47:49 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <stdlib.h>

int	ft_unset(char **vars)
{
	extern char	**environ;
	size_t		i;

	while (*vars)
	{
		if (**vars == '-')
			return (error);
		i = 0;
		while (*(environ + i))
		{
			if (getenv(*var))
				utils_update_var(*vars, NULL);
			i++;
		}
		vars++;
	}
	return (0);
}
