/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:05:19 by vim               #+#    #+#             */
/*   Updated: 2021/11/10 06:29:07 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	char_not_inhib(char lock)
{
	return (lock == 0);
}

void	command_finder(t_command *command)
{
	char	*initcmd;
	char	*pushed_chars;
	char	lock;

	initcmd = utils_strstop(command->cmd, utils_validator_isspace);
	pushed_chars = ft_strdup("");
	lock = 0;
	while (*initcmd)
	{
		if (utils_validator_isspace(*initcmd) && char_not_inhib(lock))
			break ;
		if (lock == *initcmd)
			lock = 0;
		else if ((*initcmd == '"' || *initcmd == '\'') && char_not_inhib(lock))
			lock = *initcmd;
		else
			pushed_chars = utils_strpush(pushed_chars, *initcmd);
		initcmd++;
	}
	command->argv = command_save_arguments(initcmd);
	free(command->cmd);
	command->cmd = pushed_chars;
}
