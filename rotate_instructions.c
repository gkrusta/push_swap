/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/30 18:25:44 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift down all elements of stack a by 1 */
void	reverse_rotate(t_list **lst)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *a;
	new_head = ft_lstlast(old_head);
	while (old_head)
	{
		if (old_head->next->next == NULL)
		{
			old_head->next = NULL;
			break ;
		}
		old_head = old_head->next;
	}
	old_head->next = NULL;
	new_head->next = *a;
	*a = new_head;
	printf("rra\n");
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write (1, "rra", 2);
}

void	rr(t_list **b)
{
	reverse_rotate(b);
	write (1, "rrb", 2);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr", 3);
}

/*  Shift up all elements of stack a by 1 */
void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	current = *a;
	tmp = current->next;
	*a = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
	printf("ra\n");
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
