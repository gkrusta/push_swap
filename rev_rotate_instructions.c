/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:38:04 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/01 20:26:38 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift down all elements of stack a by 1 */
void	reverse_rotate(t_list **lst)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *lst;
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
	new_head->next = *lst;
	*lst = new_head;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write (1, "rra", 3);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write (1, "rrb", 3);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr", 3);
}