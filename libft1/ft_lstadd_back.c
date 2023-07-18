/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:23:40 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/18 11:25:31 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;
	if (*lst)
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
	else
		*lst = new;
} */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
		{
			tmp = tmp->next;
			printf("IN WHILE LOOP\n");
		}
		printf("exit from loop\n\n");
		tmp->next = new;
		new->next = NULL;
	}
}
/* void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;// Set the 'prev' pointer of the new node to NULL
		new->next = NULL;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last; // Set the 'prev' pointer of the new node to the last node
	new->next = NULL; 
} */