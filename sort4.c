/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:16:39 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/05 11:51:44 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* sort 4 elements by pushing the lowest index element to the stack B at first*/
void	sort_4(t_list **a, t_list **b)
{
	if ((*a)->next->index == 1)
		sa(*a);
	else if ((*a)->next->next->index == 1)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->index == 1)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}
