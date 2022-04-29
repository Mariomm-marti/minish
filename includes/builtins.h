/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:14:19 by mortega-          #+#    #+#             */
/*   Updated: 2022/04/29 00:45:57 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <sys/types.h>

typedef ssize_t	(*t_builtin)(char const **argv, int fdin, int fdout);

/*
**	Change the current directory and update the environment variables PWD 
**	and OLDPWD
*/

ssize_t	ft_cd(char const **argv, int fdin, int fdout);

/*
**	Shows the strings or variables given as parameters (-n without '\n')
*/

ssize_t	ft_echo(char const **argv, int fdin, int fdout);

/*
**	Shows the absolute path of the current directory
*/

ssize_t	ft_pwd(char const **argv, int fdin, int fdout);

/*
**	Allow to set a empty or not empty variable to the environment variables set
**	Show a list of every variable if there is not params
*/

ssize_t	ft_export(char const **argv, int fdin, int fdout);

/*
**	Shows a list of every non-empty environment variables
*/

ssize_t	ft_env(char const **argv, int fdin, int fdout);

/*
**	Delete echa var of vars  from the environment variables set
*/

ssize_t	ft_unset(char const **argv, int fdin, int fdout);

/*
**	Exit of the program with the input code
*/

ssize_t	ft_exit(char const **argv, int fdin, int fdout);

#endif
