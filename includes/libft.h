/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:09:24 by mortega-          #+#    #+#             */
/*   Updated: 2021/09/09 17:49:47 by mortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef float	t_mat33[3][3];
typedef float	t_mat44[4][4];
typedef struct s_vec2
{
	float	x;
	float	y;
}			t_vec2;
typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}			t_coord;
typedef t_coord	t_direction;
typedef t_coord	t_point;
typedef t_coord	t_vector;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**		REGULAR FUNCTIONS
*/
void			ft_swap(void *a, void *b);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
float			ft_atof(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isnumber(char *num);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
int				ft_split_count(char *s, char c);
void			ft_split_free(char **params);
char			*ft_itoa(int c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base(int nbr, char *base);

/*
**		LIST FUNCTIONS
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
**		MATH FUNCTIONS
*/

# define INF 0xFFFFFF

void			ft_multimat44(t_mat44 mat, t_mat44 const a, t_mat44 const b);
void			ft_trasmat44(t_mat44 tras, t_mat44 const mat);
float			ft_adjmat44(t_mat44 const mat, int i, int j, float num);
float			ft_detmat33(t_mat33 mat);
float			ft_detmat44(t_mat44 const mat);
void			ft_invmat44(t_mat44 inv, t_mat44 const mat);
float			ft_dotproduct(t_vector a, t_vector b);
t_vector		ft_scalarproduct(float const num, t_vector vec);
t_vector		ft_crossproduct(t_vector a, t_vector b);
void			ft_normalize(t_vector *vector);
t_vector		ft_minusvector(t_vector a, t_vector b);
t_vector		ft_sumvector(t_vector a, t_vector b);
char			ft_quadratic(const float a, const float b, const float c,
					float *x[2]);
float			ft_modulevector(t_vector const vec);

#endif
