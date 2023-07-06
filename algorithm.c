/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/06 19:38:19 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_max(t_list *a, int index)
{
	int		max;
	t_list	*lst_a;

	max = 0;
	lst_a = a;
	while (lst_a != NULL)
	{
		if (lst_a->value > max)
			max = lst_a->index;
		lst_a = lst_a->next;
	}
	return (max);
}

int	ft_from_top(t_list **a)
{
	int	top;
	int	center;

	top = 0;
	center = argc / 2;
	while (i <= center)
	{
		if ()
		i++;
	}
	return (top);
}

int	ft_from_bottom(t_list **a, int argc)
{
	int	bottom;

	bottom = argc;
	while ()
	{
		bottom--;
	}
	return (bottom);
}

void	srt_chunks(t_list **a, t_list **b, int start, int end)
{
	int	distance_top;
	int	distance_bottom;

	distance_top = ft_from_top(a);
	distance_bottom = ft_from_bottom(a);
	if (distance_top <= distance_bottom)
	{
		while (distance_top != 1)
			distance_top--;
	}
	else
	{
		while (distance_bottom != argc)
			distance_bottom--;
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
