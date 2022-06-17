/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:36:27 by vim               #+#    #+#             */
/*   Updated: 2022/06/17 01:03:39 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <piper.h>
#include <utils.h>
#include <command.h>
#include <libft.h>
#include <sys/wait.h>
#include <signal.h>
#include <signals.h>

static bool	main_preprocess(char *line, t_command **cmds)
{
	if (!*utils_strstop(line, utils_validator_isspace))
	{
		free(line);
		return (true);
	}
	if (!utils_check_quotes(line))
	{
		printf("miniSH: quotes error\n");
		utils_update_var("?", "127");
		free(line);
		return (true);
	}
	add_history(line);
	*cmds = parser_parse(line);
	free(line);
	if (!utils_check_pipeline(*cmds))
	{
		printf("miniSH: unknown command\n");
		utils_update_var("?", "127");
		parser_free(*cmds);
		*cmds = NULL;
		return (true);
	}
	return (false);
}

static int main_execute(t_command *commands)
{
	int		status;
	size_t		i;
	int		final;
	t_tops	pds;

	pds.index_pd = 0;
	status = exec_command(commands, &pds);
	if (waitpid((pds.pds_list)[pds.index_pd - 1], &status, 0) > 0)
	{
		i = -1;
		if (kill((pds.pds_list)[pds.index_pd - 1], SIGKILL))
			while (++i < pds.index_pd)
				kill((pds.pds_list)[i], SIGKILL);
	}
	while (wait(&final) > 0)
		;
	while (status > 255)
		status = status - 255;
	return (status);
}

int	main(void)
{
	t_command	*commands;
	char		*line;
	int			status;

	environ_to_heap();
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	commands = NULL;
	while (true)
	{
		line = readline("miniSH$ ");
		if (EOF && !line)
			break ;
		if (main_preprocess(line, &commands))
			continue ;
		status = main_execute(commands);
		line = ft_itoa(status);
		utils_update_var("?", line);
		free(line);
		parser_free(commands);
	}
	free_environ();
}
