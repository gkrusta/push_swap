/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:46:53 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/23 16:52:15 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

/* libraries used */
# include "libft1/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

/* typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}				t_stack; */

/* in main */
void	ft_locate(t_list *a, int argc, char **argv);
void	ft_addindex(t_list *a);
void	ft_exit(int status);
void	ft_free_stack(char **argv);

/* instructions */
void	swap(t_list	*lst);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);

/* sort */
void	sort_3(t_list **lst_a);

/* valid number */
int	ft_valid_nb(char **new, int argc);
int	only_numbers(char **argv);
int	a_is_sorted(t_list *lst);
int	find_doubles(char **argv, int i, int nb);
int	overflow(char *str);

#endif