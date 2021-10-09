/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:39:09 by vim               #+#    #+#             */
/*   Updated: 2021/10/06 01:48:17 by vim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <stdbool.h>

char	*utils_strstop(char const *str, t_validator const validator)
{
	while (*str && validator(*str))
		str++;
	return ((char *)str);
}
