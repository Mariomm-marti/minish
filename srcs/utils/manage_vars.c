/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:36 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/15 20:17:51 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <stdlib.h>

static bool exists_var(char *var)
{
	return (getenv(var));
}

void	utils_update_var(char *var, char *content)
{
	extern char	**environ;
	char		**newenv;
	size_t		env_len;
	size_t		i;
	bool		create;

	create = exists_var(var);
	env_len = 0;
	while (*(environ + env_len))
		env_len++;
	newenv = (char **)malloc(sizeof(char *) * (env_len + 1 + create));
	i = 0;
	while (i < env_len)
	{
		if (!create && !ft_strncmp(*(environ + i), var, ft_strlen(var)))
			*(newenv + i) = utils_generate_var(var, newcont);
		else
			*(newenv + i) = *(environ + i);
		i++;
	}
	if (create)
		*(newenv + i++) = utils_generate_var(var, newcont);
	*(newenv + i) = NULL;
	environ = newenv;
}

static char	*utils_generate_var(char *var, char *newcont)
{
	char	*newvar;
	size_t	var_len;
	size_t	newcont_len;
	size_t	i;

	var_len = ft_strlen(var);
	newcont_len = ft_strlen(newcont);
	newvar = (char *)malloc(sizeof(char) * (var_len + newcont_len + 2));
	i = -1;
	while (++i < var_len)
		*(newvar + i) = *(var + i);
	*(newvar + i) = '=';
	i = -1;
	while (++i < newcont_len)
		*(newvar + var_len + i) = *(newcont + i);
	*(newvar + var_len + i) = '\0';
	return (newvar);
}

void	utils_delete_var(char *var)
{
	extern char	**environ;
	char		**newenv;
	size_t		env_len;
	size_t		i;
	char		j;

	j = 0;
	env_len = 0;
	while (*(environ + env_len))
		env_len++;
	newenv = (char **)malloc(sizeof(char *) * env_len);
	i = -1;
	while (++i < env_len)
	{
		if (!ft_strncmp(*(environ + i), var, ft_strlen(var)))
			j = 1;
		*(newenv + i) = *(environ + i + j);
	}
	*(newenv + i) = NULL;
	environ = newenv;
}
