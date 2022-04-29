/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:38:24 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 02:17:23 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <piper.h>
#include <stdlib.h>

bool	utils_validator_isspace(char const c)
{
	return (c == '\t' || c == ' ');
}

bool	utils_validator_command_line(t_command *cmd)
{
	bool	state;

	state = true;
	while (cmd)
	{
		if (!cmd->argv
			|| (seek_builtin(cmd->argv[0]) == -1 && cmd->cmd == NULL))
			state = false;
		cmd = cmd->next;
	}
	return (state);
}
