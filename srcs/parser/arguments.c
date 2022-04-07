/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:15:06 by vim               #+#    #+#             */
/*   Updated: 2022/04/03 00:49:56 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <command.h>
#include <utils.h>
#include <libft.h>

char	**push_argument(char **argv, int *argc, char *str)
{
	char	**nargv;
	int		count;

	if (!*str)
	{
		free(str);
		return (argv);
	}
	*argc = *argc + 1;
	nargv = malloc(sizeof(char *) * (*argc + 1));
	*(nargv + *argc) = NULL;
	count = 0;
	while (count < *argc - 1)
	{
		*(nargv + count) = *(argv + count);
		count++;
	}
	*(nargv + count) = str;
	free(argv);
	return (nargv);
}

void	command_do_arguments(t_command *cmd)
{
	char	*str;
	char	*current_str;
	char	lock;

	str = cmd->cmd;
	current_str = ft_strdup("");
	lock = 0;
	while (*str)
	{
		if (lock == *str)
			lock = 0;
		else if ((*str == '"' || *str == '\'') && lock == 0)
			lock = *str;
		else if (utils_validator_isspace(*str) && lock == 0)
		{
			cmd->argv = push_argument(cmd->argv, &(cmd->argc), current_str);
			current_str = ft_strdup("");
		}
		else
			current_str = utils_strpush(current_str, *str);
		str++;
	}
	cmd->argv = push_argument(cmd->argv, &(cmd->argc), current_str);
}
