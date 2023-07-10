/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:50 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/10 13:57:28 by gkrusta          ###   ########.fr       */
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
/* 
int	steps_from_bottom(t_list *lst_a, int start, int end)
{
	t_list	*final;
	t_list	*new;
	t_list	*curr;
	int		pos;
	int		i;
	int		j;

	final = lst_a;
	pos = ft_lstsize(lst_a) - 1;
	i = 0;
	new = ft_lstlast(final);
	while (pos < ft_lstsize(lst_a))
	{
		printf("steps from bottom:   value now: %d\n", new->value);
		printf("steps from bottom:   start %d and end %d\n", start, end);
		j = 0;
		if (final->value >= start && final->value <= end)
			return (i);
		curr = lst_a;
		while (j < pos)
		{
			curr = curr->next;
			j++;
		}
		final = curr;
		pos--;
		i++;
	}
	return (-1);
} */

int	steps_from_bottom(t_list *lst_a, int start, int end)
{
	int		pos;
	int		flag;
	int		count;
	t_list	*a;

	pos = 0;
	flag == 1;
	a = lst_a;
	while (pos <= ft_lstsize(lst_a))
	{
		printf("steps from bottom:   value now: %d\n", a->value);
		printf("steps from bottom:   start %d and end %d\n", start, end);
		if (a->value >= start && a->value <= end && flag == 1)
			flag = 0;
		pos++;
		a = a->next;
		if (a->value >= start && a->value <= end && flag == 0)
		{
			while (pos <= ft_lstsize(lst_a))
			{
				pos++;
				a = a->next;
				if (a->value >= start && a->value <= end)
				{
					flag = 1;
					break ;
				}
			}
		}
		if (count > 0)
			return (count);
		else
			return (-1);
	}
}

int	steps_from_top(t_list *lst_a, int start, int end)
{
	int		pos;
	t_list	*a;

	pos = 0;
	a = lst_a;
	while (pos <= ft_lstsize(lst_a))
	{
		printf("steps from top:   value now: %d\n", a->value);
		printf("steps from top:   start %d and end %d\n", start, end);
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
	printf("dist from top is: %d\n", dist_top);
	printf("dist from bottom is: %d\n", dist_bottom);
	if (dist_top <= dist_bottom || dist_bottom == -1)
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

void	sort_chunks(t_list **a, t_list **b, int start, int end)
{

	while (steps_from_top(*a, start, end) || steps_from_bottom(*a, start, end))
	{
		printf("11 dist from top is: %d\n", steps_from_top(*a, start, end));
		printf("11 dist from bottom is: %d\n", steps_from_bottom(*a, start, end));
		move_to_top(a, b, start, end);
/* 		push_to_stack_b(a, b, a->value);
 */	}
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
	size = size_of_chunk(*a, chunks); // test
	printf("start value:  %d\n", start);
	printf("max value:  %d\n", get_max(*a));
	printf("size:  %d\n", size);
	while (chunks > 0)
	{
		end = start + size;
		printf("END!!!!! :  %d\n", end);
		sort_chunks(a, b, start, end);
		start += size;
		printf("start!!!!! :  %d\n", start);
		chunks--;
	}
}
