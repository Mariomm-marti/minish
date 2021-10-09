/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:47:16 by vim               #+#    #+#             */
/*   Updated: 2021/10/06 00:50:37 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>

void	command_iterator(t_command *cmd, t_command_iter const iterator)
{
	while (cmd)
	{
		iterator(cmd);
		cmd = cmd->next;
	}
}
