/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:11:00 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 22:07:51 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <utils.h>
#include <libft.h>
#include <utils.h>

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("demasiadas veces");
		write(1, "\nminiSH$ ", 9);
		rl_on_new_line();
		//rl_redisplay();
	}
	else if (sig == SIGQUIT)
		write(1, "", 0);
	utils_update_var("?", "130");
}
