/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:02:11 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/17 13:18:55 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
/* int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	tmp = *stack_from;
	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	if (*stack_from && *stack_to == NULL)
	{
		*stack_to = malloc(sizeof(t_l
		ist));
		(*stack_to)->value = (*stack_from)->value;
		(*stack_to)->next = NULL;
		*stack_from = (*stack_from)->next;
	}
	else if (*stack_from && *stack_to)
	{
		tmp->value = (*stack_from)->value;
		tmp->next = NULL;
		ft_lstadd_front(stack_to, tmp);
		*stack_from = (*stack_from)->next;
	}
	return (0);
} */

int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_to == NULL)
	{
		*stack_to = tmp;
		(*stack_to)->next = NULL;
	}
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
	return (0);
}

/* int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
} */

/*  Take the first element at the top of b and put it at the top of a */
int	pa(t_list **stack_a, t_list **stack_b, int print)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	if (print == 0)
		ft_printf("pa\n");
	return (0);
}

/*  Take the first element at the top of a and put it at the top of b */
int	pb(t_list **stack_a, t_list **stack_b, int print)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	if (print == 0)
		ft_printf("pb\n");
	return (0);
}
