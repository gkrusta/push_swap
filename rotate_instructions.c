/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/26 19:04:17 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift down all elements of stack a by 1 */
void	rra(t_list **a)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *a;
	new_head = ft_lstlast(old_head);
	while (old_head)
	{
		if (old_head->next->next == NULL)
		{
			old_head->next = NULL;
			break ;
		}
		old_head = old_head->next;
	}
	old_head->next = NULL;
	new_head->next = *a;
	**a = *new_head;
/* 		t_list *current_sorted_a = *a;
		while (current_sorted_a)
		{
			printf("after sorting: %d\n", current_sorted_a->value);
			current_sorted_a = current_sorted_a->next;
		} */
	printf("rra\n");
}

/*  Shift up all elements of stack a by 1 */
void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*current;

	current = *a;
	tmp = current->next;
	*a = current->next;
	current->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
	printf("ra\n");
}
