/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:01:06 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/05 17:34:21 by gkrusta          ###   ########.fr       */
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
	write (1, "sa\n", 3);
}

void	sb(t_list *b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
