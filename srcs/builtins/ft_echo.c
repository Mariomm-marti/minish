/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:53:55 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/15 20:30:27 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

static bool is_correct_flag(char first_char, char next_char)
{
	return (first_char == '-' && next_char == 'n');
}

static bool check_linebreak_flag(char *param)
{
	size_t	i;
	char	first_char;
	char	next_char;

	i = 0;
	first_char = *(param);
	next_char = *(param + 1);
	if (is_correct_flag(first_char, next_char))
	{
		while (*(*param + i) == 'n')
			i++;
		if (*(*param + i) == '\0')
			return (true);
	}
	return (false);
}

int	ft_echo(char **params)
{
	size_t	len;
	size_t	i;
	bool	jump;

	jump = check_linebreak_flag(*param);
	if (jump)
		params++;
	i = 0;
	while (*(params + i))
	{
		len = ft_strlen(*(params + i));
		write(1, params + i, len);
		i++;
	}
	if (!jump)
		write(1, "\n", 1);
}
