/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/06 17:12:52 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	get_position_min(t_list *a, int index)
{
	int	min_pos;
	t_list	*lst_a;

	min_pos = 1;
	lst_a = a;
	while (lst_a != NULL)
	{
		if (lst_a->index < a->next->index)
			min_pos = a->index;
		lst_a = lst_a->next;
	}
	return (min_pos);
}

int	ft_from_top(t_list **a)
{
	int	top;

	top = 1;
	while (i >= 1)
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
void	ft_big_sort(t_list **a, t_list **b, int argc)
{
	int	chunks;
	int	start;
	
	if (argc <= 100)
		chunks = 5;
	else
		chunks = 11;
	devide_into_chunks(&a)
}
