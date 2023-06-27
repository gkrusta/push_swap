/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:45:20 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/27 13:00:09 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_min(t_list *a)
{
	t_list	*current;
	int		min;

	current = a;
	min = INT_MAX;

	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_next_min(t_list *a, int min)
{
	t_list	*current;
	int		next_min;

	current = a;
	next_min = INT_MAX;

	while (current != NULL)
	{
		if (current->value > min && current->value < next_min)
			next_min = current->value;
		current = current->next;
	}
	return (next_min);
}

void	sort_3(t_list **lst_a)
{
	t_list	*a;
	int		min;
	int		min_next;

	a = *lst_a;
	min = get_min(*lst_a);
	min_next = get_next_min(*lst_a, min);
	if (a->value == min && a->next->value != min_next)
	{
		rra(lst_a);
		sa(*lst_a);
	}
	else if (a->value == min_next && a->next->value == min)
		sa(*lst_a);
	else if (a->value == min_next && a->next->value != min)
		rra(lst_a);
	else if (a->next->value == min && a->next->next->value == min_next)
		ra(lst_a);
	else
	{
		ra(lst_a);
		sa(*lst_a);
	}
}

/* int	findLargestIndex(struct ListNode* head);
{
	while (value->next != NULL)
	{

	}
} */
