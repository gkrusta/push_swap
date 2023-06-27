/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:16:39 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/27 19:17:18 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sort_4(t_list **lst_a, t_list **lst_b)
{
	t_list	*a;
	int		min;
	int		min_next;

	a = *lst_a;
	min = get_min(*lst_a);
	min_next = get_next_min(*lst_a, min);
	if (a->value == min && a->next->value != min_next)
	{
		rra(lst_a);
		sa(*lst_a);
	}
	else if (a->value == min_next && a->next->value == min)
		sa(*lst_a);
	else if (a->value == min_next && a->next->value != min)
		rra(lst_a);
	else if (a->next->value == min && a->next->next->value == min_next)
		ra(lst_a);
	else
	{
		ra(lst_a);
		sa(*lst_a);
	}
}
