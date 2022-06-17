/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:36 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/17 18:55:50 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h> 

static char	what_action_var(char *var, char *content)
{
	if (get_env(var))
	{
		if (!content)
			return (DE);
		else
			return (CH);
	}
	return (CR);
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
		*(newvar + var_len + i + 1) = *(newcont + i);
	*(newvar + var_len + i + 1) = '\0';
	return (newvar);
}

static void	update_action(char **newenv, char *v, char *content, char c)
{
	size_t		i;
	size_t		enlen;
	bool		dlte;

	dlte = false;
	enlen = environ_len();
	i = -1;
	while (++i < enlen)
	{
		if (!ft_strncmp(*(g_environ_heap + i), v, ft_strlen(v)) && c == CH)
		{
			*(newenv + i) = utils_generate_var(v, content);
			free(*(g_environ_heap + i + dlte));
			continue ;
		}
		else if (!ft_strncmp(*(g_environ_heap + i), v, ft_strlen(v)) && c == DE)
		{
			free(*(g_environ_heap + i + dlte));
			dlte = true;
		}
		*(newenv + i) = *(g_environ_heap + i + dlte);
	}
	if (c == CR)
		*(newenv + i) = utils_generate_var(v, content);
	free(g_environ_heap);
}

void	utils_update_var(char *var, char *content)
{
	char	**newenv;
	char	chd;
	size_t	env_len;

	chd = what_action_var(var, content);
	env_len = environ_len();
	newenv = (char **)malloc(sizeof(char *) * (env_len + 1 + chd));
	*(newenv + env_len + chd) = NULL;
	if (!newenv)
		return ;
	update_action(newenv, var, content, chd);
	g_environ_heap = newenv;
}
