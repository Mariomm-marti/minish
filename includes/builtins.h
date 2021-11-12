/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:14:19 by mortega-          #+#    #+#             */
/*   Updated: 2021/11/12 20:05:56 by mortega-         ###   ########.fr       */
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

/*
**	Allow to set a empty or not empty variable to the environment variables set
**	Show a list of every variable if there is not params
*/

void	ft_export(char **params);

/*
**	Shows a list of every non-empty environment variables
*/

void	ft_env(void);

/*
**	Delete echa var of vars  from the environment variables set
*/

void	ft_unset(char **vars);

#endif
