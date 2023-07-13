/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:34:47 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/22 13:56:39 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* utils used */
void	*ft_calloc(size_t num, size_t size);
int		ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_line_len(char *str);

/* get_next_line file functions */
char	*get_next_line(int fd);
char	*ft_find_char(int fd, char *str_ac);
char	*ft_concat_free(char *str_ac, char *temp);
char	*ft_get_line(char *str_ac);
char	*ft_clear_memory(char *str_ac);

#endif