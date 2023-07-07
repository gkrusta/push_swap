/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/07 14:01:30 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_max(t_list *a)
{
	int		max;
	t_list	*lst_a;

	max = INT_MIN;
	lst_a = a;
	while (lst_a != NULL)
	{
		if (lst_a->value > max)
			max = lst_a->value;
		lst_a = lst_a->next;
	}
	return (max);
}

int	min_from_top(t_list *lst_a, int center, int start, int end)
{
	t_list	*a;
	int		pos;

	a = *lst_a;
	pos = 0;
	while (pos <= center)
	{
		if (a->value >= start && a->value <= end)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

int	min_from_bottom(t_list *lst_a, int center, int start, int end)
{
	t_list	*a;
	int		pos;

	a = *lst_a;
	pos = center * 2;// I have to change this at some point
	while (pos > center)
	{
		if (a->value >= start && a->value <= end)
			return (pos);
		a = a->next;
		pos--;
	}
	return (-1);
}

/*  */
void	push_to_stackb(t_list **a, t_list **b, int max_in_a)
{
	int	max_index;
	int	min_index;

	max_index = 
	min_index = 
}

/* move elements using ra or rra to the top of stack A */
void	move_to_top(t_list **a, int start, int end)
{
	int	dist_top;
	int	dist_bottom;

	dist_top = min_from_top(&a, center, start, end);
	dist_bottom = min_from_bottom(&a, center, start, end);
	if (dist_top <= dist_bottom)
	{
		while (dist_top > 0)
		{
			ra(a);
			dist_top--;
		}
	}
	else
	{
		while (dist_bottom > 0)
		{
			rra(a);
			dist_bottom--;
		}
	}
}

void	srt_chunks(t_list **a, t_list **b, int start, int end)
{
	int	center;

	center = argc / 2;
	while (min_from_top(&a, center, start, end) != -1
		|| min_from_bottom(&a, center, start, end) != -1)
	{
		move_to_top(a, start, end);
		push_to_stackb(a, b, a->value);
	}
}

void	ft_big_sort(t_list **a, t_list **b, int argc)
{
	int	chunks;
	int	start;
	int	size;
	int	end;

	if (argc <= 100)
		chunks = 5;
	else
		chunks = 11;
	start = get_min(&a);
	size = get_max(&a) / chunks;
	while (start <= get_max(&a))
	{
		end = start + size;
		srt_chunks(a, b, start, end);
		start += size;
	}
}
