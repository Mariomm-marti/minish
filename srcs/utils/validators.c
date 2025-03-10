/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:38:24 by vim               #+#    #+#             */
/*   Updated: 2022/04/30 10:16:19 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <piper.h>
#include <stdlib.h>

bool	utils_validator_isspace(char const c)
{
	return (c == '\t' || c == ' ');
}

bool	utils_check_quotes(char const *line)
{
	char	lock;

	lock = 0;
	while (*line)
	{
		if (lock == *line)
			lock = 0;
		else if ((*line == '"' || *line == '\'') && lock == 0)
			lock = *line;
		line++;
	}
	return (lock == 0);
}

bool	utils_check_pipeline(t_command *cmds)
{
	while (cmds)
	{
		if (cmds->argc == 0
			|| (!cmds->cmd && seek_builtin(cmds->argv[0]) == -1))
			return (false);
		cmds = cmds->next;
	}
	return (true);
}
