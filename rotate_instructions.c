/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 13:47:20 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift up all elements of stack a by 1 */
int	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	if (ft_lstsize(current) < 2)
		return (-1);
	tmp = current->next;
	*lst = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
	return (0);
}

int	ra(t_list **a, int print)
{
	if (rotate(a) == -1)
		return (-1);
	if (print == 0)
		ft_printf("ra\n");
	return (0);
}

int	rb(t_list **b, int print)
{
	if (rotate(b) == -1)
		return (-1);
	if (print == 0)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_list **a, t_list **b, int print)
{
	if (rotate(a) == -1 && rotate(b) == -1)
		return (-1);
	if (print == 0)
		ft_printf("rr\n");
	return (0);
}
