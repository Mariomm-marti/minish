/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:52:23 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/13 16:16:50 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

static void	print_content(char *content)
{
	size_t	i;

	i = 0;
	write(1, "\"", 1);
	while (*(content + i))
	{
		write(1, content + i, 1);
		i++;
	}
	write(1, "\"", 1);
	write(1, "\n", 1);
}

static bool there_is_content(char c)
{
	if (c)
	{
		write(1, "\n", 1);
		return (false);
	}
	write(1, "=", 1);
	return (true);
}

static void	show_vars(void)
{
	size_t		i;
	size_t		j;
	char		*actual_var;
	extern char	**environ;

	i = 0;
	while (*(environ + i))
	{
		j = 0;
		write(1, "declare -x ", 11);
		actual_var = *(environ + i);
		while (*(actual_var + j) && *(actual_var + j) != '=')
		{
			write(1, actual_var + j, 1);
			j++;
		}
		if (there_is_content(*(actual_var + j)))
			print_content(actual_var + j);
		i++;
	}
}

static void	separete_params(char *param, char **var, char **content)
{
	size_t	i;
	size_t	param_len;

	i = 0;
	while (*(param + i) && *(param + i) != '=')
		i++;
	param_len = ft_strlen(param);
	*var = ft_substr(param, 0, i);
	*content = ft_substr(param, i + 1, param_len - i - 1);
}

int	ft_export(char **params)
{
	extern char	**environ;
	char		*var;
	char		*content;
	size_t		i;

	if (!*params)
		show_vars();
	i = 0;
	while (*(params + i))
	{
		separete_param(*(params + i), &var, &content);
		utils_modify_var(var, content);
		i++;
	}
}
