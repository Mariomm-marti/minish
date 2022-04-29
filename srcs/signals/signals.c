/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:11:00 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 03:07:16 by mmartin-         ###   ########.fr       */
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

//TODO all-free function
void	handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\r\nminiSH$ ");
		utils_update_var("?", "130");
	}
}
