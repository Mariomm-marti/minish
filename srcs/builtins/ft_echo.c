/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:53:55 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 02:16:03 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h> ///

static bool	is_correct_flag(char first_char, char next_char)
{
	return (first_char == '-' && next_char == 'n');
}

static bool	check_linebreak_flag(char *param)
{
	size_t	i;

	i = 0;
	if (is_correct_flag(*param, *(param + 1)))
	{
		while (*(param + i + 1) == 'n')
			i++;
		if (*(param + i + 1) == '\0')
			return (true);
	}
	return (false);
}

ssize_t	ft_echo(const char **argv, int fdin, int fdout)
{
	size_t	len;
	size_t	i;
	bool	jump;
	char	**params;

	(void)fdin;
	params = (char **)(argv + 1);
	jump = check_linebreak_flag(*params);
	if (jump)
		params++;
	i = 0;
	while (*(params + i))
	{
		if (i != 0)
			write(1, " ", 1);
		len = ft_strlen(*(params + i));
		write(fdout, *(params + i), len);
		i++;
	}
	if (!jump)
		write(fdout, "\n", 1);
	return (0);
}
