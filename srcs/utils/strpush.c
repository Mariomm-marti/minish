/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vim <vim@42urduliz.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:13:35 by vim               #+#    #+#             */
/*   Updated: 2021/11/12 13:25:09 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdbool.h>

char	*utils_strpush(char *str, char const c)
{
	size_t	str_len;
	char	*final_str;

	if (!str)
		return (NULL);
	if (!c)
		return (ft_strdup(str));
	str_len = ft_strlen(str);
	final_str = malloc(str_len + 2);
	ft_memcpy(final_str, str, str_len);
	*(final_str + str_len) = c;
	*(final_str + str_len + 1) = 0;
	free(str);
	return (final_str);
}
