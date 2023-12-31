/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:01:06 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 11:00:37 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* swap first 2 elements ( sa || sb || ss ) */
void	swap(t_list	*lst)
{
	t_list	*head;
	int		tmp_value;

	head = lst;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
}

void	sa(t_list *a, int print)
{
	if (!a)
		return ;
	swap(a);
	if (print == 1)
		return ;
	else
		ft_printf("sa\n");
}

void	sb(t_list *b, int print)
{
	if (!b)
		return ;
	swap(b);
	if (print == 1)
		return ;
	else
		ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b, int print)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	if (print == 1)
		return ;
	else
		ft_printf("ss\n");
}
