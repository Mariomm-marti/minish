/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:11:00 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 22:31:02 by mortega-         ###   ########.fr       */
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
		rl_on_new_line();
		rl_point = 0;
		rl_end = 0;
		rl_line_buffer[0] = '\0';
		rl_redisplay();
		printf("|%s|\n", rl_line_buffer);
		write(1, rl_line_buffer, rl_end);

		write(1, "\nminiSH$ ", 9);
	}
	else if (sig == SIGQUIT)
		write(1, "", 0);
	utils_update_var("?", "130");
}
