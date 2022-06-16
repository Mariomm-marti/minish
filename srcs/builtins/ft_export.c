/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:52:23 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/16 23:55:24 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

static void	print_content(char *content, int fdout)
{
	size_t	i;

	i = 1;
	write(fdout, "\"", 1);
	while (*(content + i))
	{
		if (*(content + i) == '\"')
			write(1, "\\", 1);
		write(fdout, content + i, 1);
		i++;
	}
	write(fdout, "\"", 1);
	write(fdout, "\n", 1);
}

static bool	there_is_content(char c, int fdout)
{
	if (!c)
	{
		write(fdout, "\n", 1);
		return (false);
	}
	write(fdout, "=", 1);
	return (true);
}

static void	show_vars(int fdout)
{
	size_t		i;
	size_t		j;
	char		*actual_var;

	i = 0;
	while (*(g_environ_heap + i))
	{
		j = 0;
		if (ft_strncmp(*(g_environ_heap + i), "?", 1) == 0)
		{
			i++;
			continue ;
		}
		write(fdout, "declare -x ", 11);
		actual_var = *(g_environ_heap + i);
		while (*(actual_var + j) && *(actual_var + j) != '=')
		{
			write(fdout, actual_var + j, 1);
			j++;
		}
		if (there_is_content(*(actual_var + j), fdout))
			print_content(actual_var + j, fdout);
		i++;
	}
}

static bool	separete_params(char *param, char **var, char **content)
{
	size_t	i;
	size_t	param_len;

	i = 0;
	if (*(param + i) == '-' || *(param + i) == '=')
		return (false);
	while (*(param + i) && *(param + i) != '=')
		i++;
	param_len = ft_strlen(param);
	*var = ft_substr(param, 0, i);
	if (!is_valid_identifier(*var))
		return (false);
	*content = ft_substr(param, i + 1, param_len - i - 1);
	return (true);
}

ssize_t	ft_export(const char **argv, int fdin, int fdout)
{
	char		*var;
	char		*content;
	size_t		i;
	char		**params;

	(void)fdin;
	params = (char **)(argv + 1);
	if (!*params)
		show_vars(fdout);
	i = 0;
	while (*(params + i))
	{
		if (!separete_params(*(params + i), &var, &content))
			return (1);
		utils_update_var(var, content);
		free(var);
		free(content);
		i++;
	}
	return (0);
}
