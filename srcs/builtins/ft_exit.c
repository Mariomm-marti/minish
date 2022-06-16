/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:28 by mortega-          #+#    #+#             */
/*   Updated: 2022/06/16 21:47:20 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <libft.h>
#include <stdlib.h>
#include <utils.h>
#include <unistd.h>

ssize_t	ft_exit(char const **argv, int fdin, int fdout)
{
	char	*var;
	int		code;

	var = get_env("?");
	code = ft_atoi(var);
	(void)fdin;
	(void)fdout;
	free_environ();
	write(1, "exit\n", 5);
	if (*(argv + 1))
		exit(ft_atoi(*(argv + 1)));
	exit(code);
	return (0);
}
