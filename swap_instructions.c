/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:01:06 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/11 13:22:01 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* swap first 2 elements ( sa || sb || ss ) */
void	swap(t_list	*lst)
{
	t_list	*head;
	int		tmp_value;
	int		tmp_index;

	head = lst;
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = head->next->value;
	head->index = head->next->index;
	head->next->value = tmp_value;
	head->next->index = tmp_index;
}

void	sa(t_list *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_list *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
