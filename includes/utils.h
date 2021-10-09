/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:00 by vim               #+#    #+#             */
/*   Updated: 2021/10/06 19:17:57 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

typedef bool	(*t_validator)(char const);

# include <stdio.h>
/*
** Checks for \t and ' '
*/
bool	utils_validator_isspace(char const c);
/*
** Checks for everything but \'
*/
bool	utils_validator_simple_inhibitor(char const c);
/*
** Checks for everything but "
*/
bool	utils_validator_double_inhibitor(char const c);
/*
** Iterates the string until t_validator returns false
*/
char	*utils_strstop(char const *str, t_validator const validator);

#endif
