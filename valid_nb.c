/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:26 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/19 13:34:40 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	is_number(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (n >= INT_MIN && n <= INT_MAX)
		return (1);
	return (0);
}

int	a_is_sorted(t_list **lst)
{
	t_list	*head;

	head = *lst;
	if (!*lst)
		return (-1);
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}