/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2021/11/20 16:25:00 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define CREATE 1
# define CHANGE 0
# define DELETE -1

# include <stdbool.h>

typedef bool	(*t_validator)(char const);

/*
** Appends char to char const *, freeing char const *
*/
char	*utils_strpush(char *str, char const c);

/*
** Checks for \t and ' '
*/
bool	utils_validator_isspace(char const c);
/*
** Iterates the string until t_validator returns false
*/
char	*utils_strstop(char const *str, t_validator const validator);

/*
**	Change or create a new variable depending on it exits or not
*/

void	utils_update_var(char *var, char *content);

/*
**	Delete an existent environment variable
*/

void	utils_delete_var(char *var, char *newcont);

/*
**	Check if var is a valid identifier
*/

bool	is_valid_identifier(char *var);

#endif
