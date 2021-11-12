/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:13:48 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 18:51:06 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_env(void)
{
	extern char	**environ;
	size_t		i;

	while (*environ)
	{
		i = 0;
		while (*(*environ + i))
		{
			if (*(*environ + i) == '=')
			{
				write(1, *environ, ft_strlen(*environ));
				write(1, "\n", 1);
			}
			i++;
		}
		environ++;
	}
}
