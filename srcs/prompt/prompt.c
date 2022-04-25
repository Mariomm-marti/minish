/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:43:35 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/25 16:45:43 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>

static char	*relative_dir(void)
{
	char	*abs_dir;
	char	*home;
	size_t	home_len;
	size_t	abs_dir_len;
	size_t	rel_dir_len;

	home = getenv("HOME");
	abs_dir = getenv("PWD");
	home_len = ft_strlen(home);
	abs_dir_len = ft_strlen(abs_dir);
	rel_dir_len = abs_dir_len - home_len;
	if (rel_dir_len < 0)
		return (ft_strdup(abs_dir));
	return (ft_substr(abs_dir, home_len + 1, rel_dir_len));
}

static char	*print_prompt(char *user, char *home, char *abs_dir)
{
	char	*dir;
	char	*prompt;

	dir = ft_strjoin(user, "|");
	if (ft_strcmp(abs_dir, home))
		prompt = ft_strjoin(dir, relative_dir());
	else
		prompt = ft_strjoin(dir, "~");
	return (ft_strjoin(prompt, "$ "));
}

char	*show_prompt(void)
{
	char		*user;
	char		*home;
	char		*abs_dir;
	extern char	**environ;

	user = getenv("USER");
	home = getenv("HOME");
	abs_dir = getenv("PWD");
	if (!user || !home || !abs_dir)
		return(ft_strdup("minishv1.0$"));
	else
		return (print_prompt(user, home, abs_dir));
}
