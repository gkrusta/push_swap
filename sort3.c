/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:45:20 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/24 19:10:48 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_min(t_list *a)
{
	t_list	*current;
	int		min;

	current = a;
	min = INT_MIN;

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
	next_min = INT_MIN;

	while (current != NULL)
	{
		if (current->value > min && current->value < next_min)
			next_min = current->value;
		current = current->next;
	}
	return (next_min);
}

void	sort_3(t_list *lst_a)
{
	t_list	*a;
	int		min;
	int		min_next;

	a = lst_a;
	min = get_min(lst_a);
	min_next = get_next_min(lst_a, min);
	if (a->index == min && a->next->index != min_next)
	{
		rra(lst_a);
		sa(lst_a);
	}
	else if (a->index == min_next && a->next->index == min)
		sa(lst_a);
	else if (a->index == min_next && a->next->index != min)
		rra(lst_a);
	else if (a->next->index == min && a->next->next->index == min_next)
		ra(lst_a);
	else
	{
		ra(lst_a);
		sa(lst_a);
	}
}

/* int	findLargestIndex(struct ListNode* head);
{
	while (value->next != NULL)
	{

	}
} */
