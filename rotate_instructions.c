/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/01 20:19:17 by gkrusta          ###   ########.fr       */
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
	*lst = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
}

void	ra(t_list **a)
{
	rotate(a);
	write (1, "ra", 2);
}

void	rb(t_list **b)
{
	rotate(b);
	write (1, "rb", 2);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr", 2);
}
