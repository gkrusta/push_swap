/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 19:02:08 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift up all elements of stack a by 1 */
void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	tmp = current->next;
	*lst = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
}

void	ra(t_list **a, int print)
{
	rotate(a);
	if (print == 1)
		return ;
	else
		ft_printf("ra\n");
}

void	rb(t_list **b, int print)
{
	rotate(b);
	if (print == 1)
		return ;
	else
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		return ;
	else
		ft_printf("rr\n");
}
