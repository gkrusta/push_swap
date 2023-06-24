/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:11:38 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/24 19:10:29 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*  Shift down all elements of stack a by 1 */
void	rra(t_list *a)
{
	t_list	*tmp;
	t_list	*current;
	int		index;

	tmp = ft_lstlast(a);
	current = a;
	index = 0;
	while (current != NULL)
	{
		current->index = index + 1;
		current = current->next;
		index++;
	}
	printf("rra\n");
}

/*  Shift up all elements of stack a by 1 */
void	ra(t_list *a)
{
	int		tmp;
	t_list	*current = NULL;
	int	index;

	tmp = current->value;
	current = a->next;
	index = 0;
	while (current != NULL)
	{
		current->index = index - 1;
		current = current->next;
		index--;
	}
	current->next->value = tmp;
	printf("ra\n");
}
