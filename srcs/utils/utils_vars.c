/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:21:55 by mortega-          #+#    #+#             */
/*   Updated: 2022/01/15 17:11:48 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

bool	is_valid_identifier(char *var)
{
	size_t	i;
	size_t	var_len;

	var_len = ft_strlen(var);
	i = 0;
	while (i < var_len)
	{
		if (!ft_isalnum(*(var + i)))
			return (false);
		i++;
	}
	return (true);
}
