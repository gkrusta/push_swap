/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:16:39 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/05 18:09:16 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* sort 4 elements by pushing the lowest index element to the stack B at first*/
void	sort_4(t_list **a, t_list **b, int flag)
{
	if ((*a)->next->index == flag)
		sa(*a);
	else if ((*a)->next->next->index == flag)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->index == flag)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}
