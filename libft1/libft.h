/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:21:13 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/22 16:48:00 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Libraries used */

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

/* functions from <stdlib.h> */
int		ft_atoi(const char	*str);
void	*ft_calloc(size_t num, size_t size);

/* functions from <ctype.h> */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* functions from <string.h> */
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *haystak, const char *to_find, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);

/* non standart functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* bonus functions */
typedef struct s_list
{
	int	*content;
	int	value; // adding these elements for push_swap
	int	index;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* functions added for push_swap */
long	ft_long_atoi(const char	*str);
int		ft_strcmp(const char *s1, const char *s2);

#endif