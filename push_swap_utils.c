/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:39:01 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 14:17:23 by gkrusta          ###   ########.fr       */
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

/* find the max value in the stack */
int	get_max(t_list *lst)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = lst;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

/* depending on the int value size of the chunks changes */
int	size_of_chunk(t_list *a, int chunks)
{
	int	size;
	int	max;
	int	min;

	max = get_max(a);
	min = get_min(a);
	if (max < 0 && min < 0)
		size = (-1) * (max + min);
	else if (max < 0 && min > 0)
		size = ((-1) * max + min);
	else if (max > 0 && min < 0)
		size = ((-1) * min + max);
	else
		size = max - min;
	while (size % chunks != 0)
		size++;
	return (size / chunks);
}

/* looks how many steps from the top is the max value in the stack b */
int	max_to_top(t_list *lst_b, int value)
{
	int		pos;
	t_list	*b;

	pos = 0;
	b = lst_b;
	while (b != NULL && pos <= ft_lstsize(lst_b))
	{
		if (b->value == value)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}
