/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:45:20 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/19 13:46:32 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sort_3(t_stack **lst_a)
{
	t_stack	*a;
	int	min_nb;
	int	min_next_nb;

	a = *lst_a;
	min_nb = get_min(lst_a, );
	min_next_nb = get_next_min(lst_a, min);
	if (a_is_sorted(lst_a))
		return ;

}

/* int	findLargestIndex(struct ListNode* head);
{
	while (value->next != NULL)
	{

	}
} */