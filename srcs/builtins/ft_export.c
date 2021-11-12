/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:52:23 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 20:01:51 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

static void	show_vars(void)
{
	size_t		i;
	size_t		j;
	extern char	**environ;

	i = 0;
	while (*(environ + i))
	{
		j = 0;
		write(1, "declare -x ", 11);
		while (*(*(environ + i) + j) != '=' && *(*(environ + i) + j) != '\0')
			write(1, *(environ + i) + j++, 1);
		if (*(*(environ + i) + j) == '\0')
		{
			i += write(1, "\n", 1);
			continue ;
		}
		write(1, *(environ + i) + j++, 1);
		write(1, "\"", 1);
		while (*(*(environ + i) + j))
			write(1, *(environ + i) + j++, 1);
		write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_export(char **params)
{
	extern char	**environ;

	if (!*params)
		show_vars();
	while (*params)
	{
		utils_create_var(*params);
		params++;
	}
}
