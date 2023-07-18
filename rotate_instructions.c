/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/18 11:43:15 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift up all elements of stack a by 1 */
void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	tmp = current->next;
	/* tmp = *lst; */
	*lst = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("current value: %d\n\n", current->value);
	tmp->next = current;
	 	t_list *current_a = *lst;
	while (current_a)
	{
		printf("in rotate: %d\n", current_a->value);
		current_a = current_a->next;
	}
}

void	ra(t_list **a, int print)
{
	rotate(a);
/* 	printf("!!!HERE\n\n");
 */	if (print == 1)
		return ;
	else
		ft_printf("ra\n");
}

void	rb(t_list **b, int print)
{
	rotate(b);
	if (print == 1)
		return ;
	else
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		return ;
	else
		ft_printf("rr\n");
}
