/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2022/06/17 00:16:42 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define CR 1
# define CH 0
# define DE -1

# include <stdbool.h>
# include <command.h>
# include <sys/types.h>

/*
**	GLOBAL VARIABLE
*/
char			**g_environ_heap;

typedef bool	(*t_validator)(char const);

/*
** Appends char to char const *, freeing char const *
*/
char			*utils_strpush(char *str, char const c);

/*
** Checks for \t and ' '
*/
bool			utils_validator_isspace(char const c);

bool			utils_check_quotes(char const *line);

bool			utils_check_pipeline(t_command *cmds);

/*
** Iterates the string until t_validator returns false
*/
char			*utils_strstop(char const *str, t_validator const validator);

/*
**	Change or create a new variable depending on it exits or not
*/

void			utils_update_var(char *var, char *content);

/*
**	Check if var is a valid identifier which means var is composed by
**	isalnum characters
*/

bool			is_valid_identifier(char *var);

/*
**	Does a copy of the environment variables into the heap memory
*/

void			environ_to_heap(void);

/*
**	Return the number of variables on extern environ
*/

size_t			environ_len(void);

/*
**	Environ memory free
*/

void			free_environ(void);

/*
** Getenv local implementation
*/
char			*get_env(char const *name);

#endif
