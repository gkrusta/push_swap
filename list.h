/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:46:53 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/10 18:31:51 by gkrusta          ###   ########.fr       */
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
void	ft_exit(int status);
void	ft_free_stack(char **argv);
int		new_argc(char **argv);
void	delete_last_element(t_list **stack);

/* index */
void	ft_addindex(t_list **a, int argc, char **argv, int saver);
void	ft_addindex_str(t_list **a, int argc, char **argv);
char	**ft_sort_params(int argc, char **argv, int check);


/* swap instructions */
void	swap(t_list	*lst);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);

/* push instructions */
int		push(t_list **stack_from, t_list **stack_to);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

/* rotate instructions */
void	rotate(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

/* reverse rotate instructions */
void	reverse_rotate(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

/* sort */
int		get_min(t_list *a);
int		get_next_min(t_list *a, int min);
void	sort_3(t_list **lst_a);
void	sort_4(t_list **a, t_list **b, int flag);
void	sort_5(t_list **a, t_list **b);

/* valid number */
int		ft_valid_nb(char **new, int argc, int i);
int		only_numbers(char **argv);
int		a_is_sorted(t_list *lst);
int		find_doubles(char **argv, int i, int nb);
int		overflow(char *str);

/* algorithm */
void	ft_big_sort(t_list **a, t_list **b, int argc);
void	sort_chunks(t_list **a, t_list **b, int start, int end);
void	move_to_top(t_list **a, t_list **b, int start, int end);
int	steps_from_top(t_list *lst_a, int start, int end);
int	steps_from_bottom(t_list *lst_a, int start, int end);
int	get_max(t_list *a);
int	size_of_chunk(t_list *a, int chunks);
void	move_to_a(t_list **a, t_list **b);

#endif