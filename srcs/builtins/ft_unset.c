/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:20 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/13 16:17:02 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <stdlib.h>

void	ft_unset(char **vars)
{
	extern char	**environ;
	size_t		i;

	while (*vars)
	{
		i = 0;
		while (*(environ + i))
		{
			if (getenv(*var))
				utils_delete_var(*vars);
			i++;
		}
		vars++;
	}
}
