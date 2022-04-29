/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:38:24 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 21:22:43 by mortega-         ###   ########.fr       */
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
		if (!cmds->cmd || ft_split_count(cmds->argv) == 0)
			return (false);
		cmds = cmds->next;
	}
	return (true);
}
