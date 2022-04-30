/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:58:20 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/30 09:55:09 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <utils.h>
#include <stdlib.h>

ssize_t	ft_unset(const char **argv, int fdin, int fdout)
{
	extern char	**environ;
	char		**vars;

	(void)fdin;
	(void)fdout;
	vars = (char **)(argv + 1);
	while (*vars)
	{
		if (!is_valid_identifier(*vars))
			return (1);
		if (getenv(*vars))
			utils_update_var(*vars, NULL);
		vars++;
	}
	return (0);
}
