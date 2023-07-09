/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/09 14:22:54 by gkrusta          ###   ########.fr       */
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

/* checks if the top value of stack B is > or < than the top value of stack A */
/* int	check_top_stack_b(t_list *lst_b, int top_a)
{
	t_list	*b;
	int		smallest;
	int		biggest;

	b = *lst_b;
	smallest = b->value;
	biggest = b->value;
	while (b->next != NULL)
	{
		if (top_a > b->value)
			biggest = b->value;
		else if (top_a < b->value)
			smallest = b->value;
		b = b->next;
	}
	if (top_a > biggest)
		return (1);
	else
		return (-1);
} */

/* push elements on top of the stack b */
/* void	push_to_stack_b(t_list **a, t_list **b, int max_in_a)
{
	int	max_index;
	int	min_index;

	max_index = max_index(&b);
	min_index = min_index(&b);


} */

int	steps_from_bottom(t_list *lst_a, int center, int start, int end)
{
	t_list	*a;
	t_list	*current;
	int		pos;
	int		i;
	int		j;

	a = lst_a;
	pos = ft_lstsize(lst_a) - 1;
	i = 0;
	while (pos > center)
	{
		if (a->value <= start && a->value >= end)
			return (i);
		j = 0;
		while (j <= pos) // - 1??
		{
			current = current->next;
			j++;
		}
		a = current;
		pos--;
		i++;
		a = a->next;
	}
	return (-1);
}

int	steps_from_top(t_list *lst_a, int center, int start, int end)
{
	int		pos;
	t_list	*a;

	pos = 0;
	a = lst_a;
	while (pos <= center)
	{
		if (a->value <= start && a->value >= end)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

/* move elements using ra or rra to the top of stack A */
void	move_to_top(t_list **a, t_list **b, int center, int start, int end)
{
	int	dist_top;
	int	dist_bottom;

	dist_top = steps_from_top(*a, center, start, end);
	dist_bottom = steps_from_bottom(*a, center, start, end);
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
	pb(a, b);
}

void	sort_chunks(t_list **a, t_list **b, int argc, int start, int end)
{
	int	center;

	center = argc / 2;
	while (steps_from_top(*a, center, start, end) != -1
		|| steps_from_bottom(*a, center, start, end) != -1)
	{
		move_to_top(a, b, center, start, end);
/* 		push_to_stack_b(a, b, a->value);
 */	}
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
	start = get_min(*a);
	size = get_max(*a) / chunks; //need to fix
	printf("start value:  %d\n", start);
	printf("max value:  %d\n", get_max(*a));
	printf("size:  %d\n", size);
	while (start <= get_max(*a))
	{
		end = start + size;
		sort_chunks(a, b, argc, start, end);
		start += size;
	}
}
