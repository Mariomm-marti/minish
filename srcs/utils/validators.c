/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:38:24 by vim               #+#    #+#             */
/*   Updated: 2021/10/06 01:50:31 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	utils_validator_isspace(char const c)
{
	return (c == '\t' || c == ' ');
}

bool	utils_validator_simple_inhibitor(char const c)
{
	return (c != '\'');
}

bool	utils_validator_double_inhibitor(char const c)
{
	return (c != '"');
}
