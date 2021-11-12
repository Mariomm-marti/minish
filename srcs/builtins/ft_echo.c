/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:53:55 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 13:13:20 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

int	ft_echo(char **params)
{
	int		i;
	char	jump;

	i = 0;
	jump = 0;
	if (*params && *(*params + i++) == '-')
	{
		while (*(*params + i) == 'n')
			i++;
		if (*(*params + i) == '\0')
			jump = 1;
		params++;
	}
	while (*params)
	{
		while (**params)
		{
			write(1, *params, 1);
			(*params)++;
		}
		params++;
	}
	if (!jump)
		write(1, "\n", 1);
}
