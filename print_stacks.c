/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:26:56 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 14:25:44 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*current_a_index;
	t_list	*current_sorted_b;
	t_list	*current_sorted_a;

	current_a = a;
	current_a_index = a;
	current_sorted_b = b;
	current_sorted_a = a;
	while (current_a)
	{
		printf("before sorting list A: %d  --  ", current_a->value);
		if (current_a_index)
		{
			printf("index : %d\n", current_a_index->index);
			current_a_index = current_a_index->next;
		}
		current_a = current_a->next;
	}
	printf("-----\n");
	while (current_sorted_b)
	{
		printf("after sorting stack B:  %d\n", current_sorted_b->value);
		current_sorted_b = current_sorted_b->next;
	}
	printf("-----\n");
	while (current_sorted_a)
	{
		printf("after sorting stack A:  %d\n", current_sorted_a->value);
		current_sorted_a = current_sorted_a->next;
	}
}
