/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:28 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/08 00:11:24 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdlib.h>

ssize_t  ft_exit(char const **argv, int fdin, int fdout)
{
	(void)fdin;
	(void)fdout;
	exit(ft_atoi(*(argv + 1)));
	return (0);
}
