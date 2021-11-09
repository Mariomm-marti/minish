/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:05:19 by vim               #+#    #+#             */
/*   Updated: 2021/11/09 04:10:02 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static char	**command_save_arguments(char const *str)
{
	char	**argv;
	char	*splitted_arguments;
	size_t	str_len;

	if (!str)
		return (NULL);
	argv = malloc(sizeof(char *));
	if (!argv)
		return (NULL);
	str_len = ft_strlen(str);
	splitted_arguments = malloc(str_len + 1);
	if (!splitted_arguments)
	{
		free(argv);
		return (NULL);
	}
	ft_memcpy(splitted_arguments, str, str_len + 1);
	*argv = splitted_arguments;
	return (argv);
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
		if (utils_validator_isspace(*initcmd) && lock == 0)
			break ;
		if (lock == *initcmd)
			lock = 0;
		else if ((*initcmd == '"' || *initcmd == '\'') && lock == 0)
			lock = *initcmd;
		else
			pushed_chars = utils_strpush(pushed_chars, *initcmd);
		initcmd++;
	}
	command->argv = command_save_arguments(initcmd);
	free(command->cmd);
	command->cmd = pushed_chars;
}
