/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:31:30 by vim               #+#    #+#             */
/*   Updated: 2021/12/11 22:17:13 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command.h>
#include <utils.h>
#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	should_resolve_var(char const current_char, bool const is_inhibed)
{
	if (current_char == '$')
		return (!is_inhibed);
	return (false);
}

static bool	get_new_inhib_state(char const current_char, bool const inhib_state)
{
	if (current_char == '\'')
		return (!inhib_state);
	return (inhib_state);
}

static char	*get_var_endp(char *cmdstr)
{
	if (*cmdstr != '$')
		return (cmdstr);
	cmdstr++;
	if (!ft_isalpha(*cmdstr))
		return (cmdstr - 1);
	while (ft_isalnum(*cmdstr) || *cmdstr == '_')
		cmdstr++;
	return (cmdstr - 1);
}

static char	*resolve_var(char *user_in, char *resolved)
{
	size_t const	var_len = (size_t)(get_var_endp(user_in) - user_in);
	char			*var_name;
	char			*var_content;

	var_name = ft_substr(user_in, 1, var_len);
	var_content = getenv(var_name);
	if (!var_content)
	{
		free(var_name);
		return (resolved);
	}
	while (*var_content)
	{
		resolved = utils_strpush(resolved, *var_content);
		var_content++;
	}
	free(var_name);
	return (resolved);
}

void	command_replace_vars(t_command *cmd)
{
	char	*cmdstr;
	char	*finalstr;
	bool	inhib_state;

	cmdstr = cmd->cmd;
	finalstr = ft_strdup("");
	inhib_state = false;
	while (*cmdstr)
	{
		if (!should_resolve_var(*cmdstr, inhib_state)
				|| get_var_endp(cmdstr) == cmdstr)
			finalstr = utils_strpush(finalstr, *cmdstr);
		else
		{
			finalstr = resolve_var(cmdstr, finalstr);
			cmdstr = get_var_endp(cmdstr);
		}
		inhib_state = get_new_inhib_state(*cmdstr, inhib_state);
		cmdstr++;
	}
	free(cmd->cmd);
	cmd->cmd = finalstr;
}

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
int		main(void)
{
	t_command	command;

	command.cmd = readline("miniSH$ ");
	command_replace_vars(&command);
	printf("\nFINAL:\n%s\n", command.cmd);
	free(command.cmd);
}
