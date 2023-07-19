/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 19:12:52 by gkrusta          ###   ########.fr       */
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

/* calculate how many movements it takes to move the smallest int from bottom */
int	steps_from_bottom(t_list *lst_a, int start, int end)
{
	int		pos;
	int		flag;
	int		count;
	t_list	*a;

	pos = 0;
	flag = 0;
	count = 0;
	a = lst_a;
	while (pos <= ft_lstsize(lst_a) - 1)
	{
		if (a->value >= start && a->value <= end)
		{
			flag = 1;
			count = 0;
		}
		count++;
		pos++;
		a = a->next;
	}
	if (count > 0 && flag == 1)
		return (count);
	else
		return (-1);
}

/* calculate how many movements it takes to move the smallest int from top */
int	steps_from_top(t_list *lst_a, int start, int end)
{
	int		pos;
	t_list	*a;

	pos = 0;
	a = lst_a;
	while (a != NULL && pos <= ft_lstsize(lst_a))
	{
		if (a->value >= start && a->value <= end)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

/* move elements using ra or rra to the top of stack A */
void	move_to_top(t_list **a, t_list **b, int start, int end)
{
	int	dist_top;
	int	dist_bottom;

	dist_top = steps_from_top(*a, start, end);
	dist_bottom = steps_from_bottom(*a, start, end);
	if (dist_top <= dist_bottom || dist_bottom == -1)
	{
		while (dist_top > 0)
		{
			ra(a, 0);
			dist_top--;
		}
	}
	else
	{
		while (dist_bottom > 0)
		{
			rra(a, 0);
			dist_bottom--;
		}
	}
	pb(a, b, 0);
}

void	sort_chunks(t_list **a, t_list **b, int start, int end)
{
	while (steps_from_top(*a, start, end) != -1 && steps_from_bottom(*a, start, end) != -1 )
	{
		move_to_top(a, b, start, end);
	}
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

void	move_to_a(t_list **a, t_list **b)
{
	int	dist_top;
	int	dist_bottom;
	int	top;

	while (*b)
	{
		top = get_max(*b);
		dist_top = max_to_top(*b, top);
		dist_bottom = ft_lstsize(*b) - dist_top;
		if (dist_top <= dist_bottom)
		{
			while (dist_top > 0)
			{
				rb(b, 0);
				dist_top--;
			}
		}
		else
		{
			while (dist_bottom > 0)
			{
				rrb(b, 0);
				dist_bottom--;
			}
		}
		pa(a, b, 0);
	}
}

void	ft_big_sort(t_list **a, t_list **b, int argc)
{
	int	chunks;
	int	start;
	int	size;
	int	end;

	if (argc < 102)
		chunks = 5;
	else
		chunks = 11;
	start = get_min(*a);
	size = size_of_chunk(*a, chunks);
	while (chunks > 0)
	{
		end = start + size;
		sort_chunks(a, b, start, end);
		start += size;
		chunks--;
	}
	move_to_a(a, b);
}
