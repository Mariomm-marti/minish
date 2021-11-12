/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:14:19 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 13:21:55 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
**	Change the current directory and update the environment variables PWD 
**	and OLDPWD
*/

int		ft_cd(const char *path);

/*
**	Shows the strings or variables given as parameters (-n without '\n')
*/

void	ft_echo(char **params);

/*
**	Shows the absolute path of the current directory
*/

void	ft_pwd(void);

#endif
