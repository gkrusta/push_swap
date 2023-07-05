/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:58:07 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/05 17:06:58 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sort_5(t_list **a, t_list **b)
{
	if ((*a)->next->index == 1)
		sa(*a);
	else if ((*a)->next->next->index == 1)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->index == 1)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->index == 1)
		rra(a);
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}