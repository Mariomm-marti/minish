/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:52:23 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 18:48:15 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

static void	print_content(char *content, int fdout)
{
	size_t	i;

	i = 0;
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

static bool there_is_content(char c, int fdout)
{
	if (c)
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
		if (there_is_content(*(actual_var + j), fdout))
			print_content(actual_var + j, fdout);
		i++;
	}
}

static bool	separete_params(char *param, char **var, char **content)
{
	size_t	i;
	size_t	j;
	size_t	param_len;

	i = 0;
	if (*(param + i) == '-')
		return (false);
	while (*(param + i) && *(param + i) != '=')
		i++;
	param_len = ft_strlen(param);
	*var = ft_substr(param, 0, i);
	if (!is_valid_identifier(*var))
		return (false);
	*content = ft_substr(param, i + 1, param_len - i - 1);
	if (!is_valid_identifier(*content))
		return (false);
	return (true);
}

ssize_t	ft_export(const char **argv, int fdin, int fdout)
{
	char		*var;
	char		*content;
	size_t		i;
	char		**params;

	params = argv;
	if (!*params)
		show_vars(fdout);
	i = 0;
	while (*(params + i))
	{
		if (!separete_param(*(params + i), &var, &content))
			return (1);
		utils_modify_var(var, content);
		i++;
	}
	return (0);
}
