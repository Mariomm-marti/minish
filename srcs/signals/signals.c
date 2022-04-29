/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:11:00 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 01:59:43 by mortega-         ###   ########.fr       */
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
		// all-free function
		printf("\r\nminiSH$ ");
		utils_update_var("?", "130");
	}
}
