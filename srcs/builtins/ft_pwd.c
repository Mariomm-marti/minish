/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:48:16 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 16:13:31 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

int	ft_pwd(char **args)
{
	char	*buf;

	if (**args == '-')
		return (1);
	buf = getcwd(NULL, 0);
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	return (0);
}
