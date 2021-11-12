/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2021/11/12 13:32:52 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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
**	A prior it does the same that getenv()
*/

char	*utils_search_var(char **env, char *var);

/*
**	Create a environment variable with its content
*/

char	*utils_generate_var(char *var, char *newcont);

/*
**	Change the value of a existent environment variable
*/

void	utils_change_var(char *var, char *newcont);

#endif
