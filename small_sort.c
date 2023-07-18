/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:45:20 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/18 14:07:17 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* returns the minimum value */
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

/* returns the next minimum value */
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

/* sorts 3 elements in the stack a */
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
		rra(lst_a, 0);
		sa(*lst_a, 0);
	}
	else if (a->value == min_next && a->next->value == min)
		sa(*lst_a, 0);
	else if (a->value == min_next && a->next->value != min)
		rra(lst_a, 0);
	else if (a->next->value == min && a->next->next->value == min_next)
		ra(lst_a, 0);
	else
	{
		ra(lst_a, 0);
		sa(*lst_a, 0);
	}
}

/* sort 4 elements by pushing the lowest index element to the stack B at first*/
void	sort_4(t_list **a, t_list **b, int flag)
{
	if ((*a)->next->index == flag)
		sa(*a, 0);
	else if ((*a)->next->next->index == flag)
	{
		ra(a, 0);
		ra(a, 0);
	}
	else if ((*a)->next->next->next->index == flag)
		rra(a, 0);
	pb(a, b, 0);
	sort_3(a);
	pa(a, b, 0);
}

/* sort 5 elements by pushing the lowest index element to the stack B at first*/
void	sort_5(t_list **a, t_list **b)
{
	if ((*a)->next->index == 1)
		sa(*a, 0);
	else if ((*a)->next->next->index == 1)
	{
		ra(a, 0);
		ra(a, 0);
	}
	else if ((*a)->next->next->next->index == 1)
	{
		rra(a, 0);
		rra(a, 0);
	}
	else if ((*a)->next->next->next->next->index == 1)
		rra(a, 0);
	pb(a, b, 0);
	sort_4(a, b, 2);
	pa(a, b, 0);
}
