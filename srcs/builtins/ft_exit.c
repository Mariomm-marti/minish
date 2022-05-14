/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:28 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 02:16:36 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdlib.h>
#include <utils.h>

ssize_t	ft_exit(char const **argv, int fdin, int fdout)
{
	(void)fdin;
	(void)fdout;
	free_environ();
	exit(ft_atoi(*(argv + 1)));
	return (0);
}
