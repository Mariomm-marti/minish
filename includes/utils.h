/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2021/10/29 01:06:19 by vim              ###   ########.fr       */
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

#endif
