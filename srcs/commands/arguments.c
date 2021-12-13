/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:46:36 by vim               #+#    #+#             */
/*   Updated: 2021/12/13 17:58:31 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static char	get_next_inhib_state(char const current_char, char const actual)
{
	if (actual == current_char)
		return ('\0');
	if (actual == '\0' && utils_validator_isspace(current_char))
		return (' ');
	if (current_char == '"' || current_char == '\'')
		return (current_char);
	return (actual);
}

void	command_arguments(t_command *cmd)
{
	char	*cmdstr;
	char	lock;

	cmdstr = cmd->cmd;
	lock = get_next_inhib_state(*cmdstr, lock);
	while (*cmdstr)
	{
		lock = get_next_inhib_state(*cmdstr, lock);
		cmdstr++;
	}
}
