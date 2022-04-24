/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:11:00 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/24 12:29:05 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <utils.h>

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		// all-free function
		write(1, "\n", 1);
		show_prompt();
		//exit(130);
	}
	else if (sig == SIGQUIT)
		;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
