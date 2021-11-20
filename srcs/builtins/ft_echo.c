/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:53:55 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 15:33:52 by mortega-         ###   ########.fr       */
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

	i = 0;
	if (is_correct_flag(*param, *(param + 1)))
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


	if (!is_correct_flag(**param, *(*(param + 1))))
		return (error);
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
	return (0);
}
