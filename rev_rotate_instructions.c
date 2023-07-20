/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:38:04 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 13:47:28 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift down all elements of stack a by 1 */
int	reverse_rotate(t_list **lst)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *lst;
	if (ft_lstsize(old_head) < 2)
		return (-1);
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
	return (0);
}

int	rra(t_list **a, int print)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	if (print == 0)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **b, int print)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	if (print == 0)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **a, t_list **b, int print)
{
	if (reverse_rotate(a) == -1 && reverse_rotate(b) == -1)
		return (-1);
	if (print == 0)
		ft_printf("rrr\n");
	return (0);
}
