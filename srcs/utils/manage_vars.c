/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:36 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 18:42:11 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <builtines.h>
#include <stdlib.h>
#include <stdio.h>

char	*utils_search_var(char **env, char *var)
{
	size_t	len;

	len = ft_strlen(var);
	while (*env)
	{
		if (!ft_strncmp(var, *env, len))
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}

char	*utils_generate_var(char *var, char *newcont)
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

void	utils_change_var(char *var, char *newcont)
{
	extern char	**environ;
	char		**newenv;
	size_t		env_len;
	size_t		i;

	env_len = 0;
	while (*(environ + env_len))
		env_len++;
	newenv = (char **)malloc(sizeof(char *) * (env_len + 1));
	i = 0;
	while (i < env_len)
	{
		if (!ft_strncmp(*(environ + i), var, ft_strlen(var)))
			*(newenv + i) = utils_generate_var(var, newcont);
		else
			*(newenv + i) = *(environ + i);
		i++;
	}
	*(newenv + i) = NULL;
	environ = newenv;
}

void	utils_create_var(char *var)
{
	extern char	**environ;
	char		**newenv;
	size_t		env_len;
	size_t		i;

	env_len = 0;
	while (*(environ + env_len))
		env_len++;
	newenv = (char **)malloc(sizeof(char *) * (env_len + 2));
	i = -1;
	while (++i < env_len)
		*(newenv + i) = *(environ + i);
	*(newenv + i++) = utils_generate_var(var, NULL);
	*(newenv + i) = NULL;
	environ = newenv;
}	
