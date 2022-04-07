/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:36 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/08 00:15:49 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static char	what_action_var(char *var, char *content)
{
	if (getenv(var))
	{
		if (!content)
			return (DELETE);
		else
			return (CHANGE);
	}
	return (CREATE);
}

static size_t	environ_len(void)
{
	extern char	**environ;
	size_t		env_len;

	env_len = 0;
	while (*(environ + env_len))
		env_len++;
	return (env_len);
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
	if (!newvar)
		return (NULL);
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

static void	update_action(char **newenv, char *var, char *content, char chd)
{
	extern char	**environ;
	size_t		env_len;
	size_t		i;
	bool		dlte;

	dlte = false;
	env_len = environ_len();
	i = 0;
	while (i < env_len)
	{
		if (!ft_strncmp(*(environ + i), var, ft_strlen(var)))
		{
			if (chd == CHANGE)
				*(newenv + i) = utils_generate_var(var, content);
			else if (chd == DELETE)
				dlte = true;
		}
		else
			*(newenv + i) = *(environ + i + dlte);
		i++;
	}
	if (chd == CREATE)
		*(newenv + i) = utils_generate_var(var, content);
	*(newenv + i) = NULL;
	environ = newenv;
}

void	utils_update_var(char *var, char *content)
{
	char	**newenv;
	char	chd;
	size_t	env_len;

	chd = what_action_var(var, content);
	env_len = environ_len();
	newenv = (char **)malloc(sizeof(char *) * (env_len + 1 + chd));
	if (!newenv)
		return ;
	update_action(newenv, var, content, chd);
}
