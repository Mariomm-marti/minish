/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:21:55 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/15 23:20:34 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdlib.h>
#include <utils.h>
#include <stdbool.h>

bool	is_valid_identifier(char *var)
{
	size_t	i;
	size_t	var_len;

	var_len = ft_strlen(var);
	i = 0;
	while (i < var_len)
	{
		if (!ft_isalnum(*(var + i)) && !utils_validator_isspace(*(var + i)))
			return (false);
		i++;
	}
	return (true);
}

size_t   environ_len(void)
{
	size_t          env_len;
	
	env_len = 0;
	while (*(newenv + env_len))
		env_len++;
	return (env_len);
}

void	environ_to_heap(void)
{
	size_t          envlen; 
	size_t          i;
	extern char     **environ;
	
	envlen = 0;
	while (*(environ + envlen))
		envlen++;
	newenv = (char **)malloc(sizeof(char *) * (envlen + 1));
	i = 0;
	while (i < envlen)
	{
		*(newenv + i) = ft_strdup(*(environ + i));
		i++;
	}
	*(newenv + i) = NULL;
}

void	free_environ(void)
{
	size_t		envlen;
	size_t		i;

	envlen = environ_len();
	i = 0;
	while (i < envlen)
	{
		free(*(environ_heap + i));
		i++;
	}
	free(environ_heap);
}
