/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:01:07 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/10 13:26:22 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(int));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/* int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	head = ft_lstnew(1);
	second = ft_lstnew(2);
	third = ft_lstnew(3);

	head->next = second;
	second->next = third;
	third->next = NULL;
	return (0);
} */