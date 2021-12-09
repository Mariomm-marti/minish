/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:48:16 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/20 18:49:45 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <unistd.h>

ssize_t	ft_pwd(const char **argv, int fdin, int fdout)
{
	char	*buf;

	if (**argv == '-')
		return (1);
	buf = getcwd(NULL, 0);
	write(fdout, buf, ft_strlen(buf));
	write(fdout, "\n", 1);
	return (0);
}
