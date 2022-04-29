/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2022/04/29 01:36:15 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define CREATE 1
# define CHANGE 0
# define DELETE -1

# include <stdbool.h>
# include <command.h>

typedef bool	(*t_validator)(char const);

/*
** Appends char to char const *, freeing char const *
*/
char	*utils_strpush(char *str, char const c);

/*
** Checks for \t and ' '
*/
bool	utils_validator_isspace(char const c);

bool	utils_validator_command_line(t_command *cmd);

/*
** Iterates the string until t_validator returns false
*/
char	*utils_strstop(char const *str, t_validator const validator);

/*
**	Change or create a new variable depending on it exits or not
*/

void	utils_update_var(char *var, char *content);

/*
**	Check if var is a valid identifier which means var is composed by
**	isalnum characters
*/

bool	is_valid_identifier(char *var);

/*
** Displays the beginning of the prompt line to the user
*/
char	*show_prompt(void);

#endif
