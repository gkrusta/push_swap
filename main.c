/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/16 21:46:48 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* declare 2 stacks */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (-1);
	a = malloc(sizeof(t_list));
	//b = ft_lstnew(0);
	ft_locate(a, argc, argv);
/* 	t_list *current_a = a;
	while (current_a)
	{
		printf("before sorting: %d\n", current_a->value);
		current_a = current_a->next;
	}
	printf("list size is %d\n\n", ft_lstsize(a));
	printf("argc %d", argc);
	t_list *current_a_index = a;
	while (current_a_index != NULL)
	{
		printf("index: %d\n", current_a_index->index);
		current_a_index = current_a_index->next;
	}
	printf("\n"); */
	if (a_is_sorted(a) == 1)
	{
		free (a);
		return (0);
	}
	if (ft_lstsize(a) < 6)
		ft_small_sort(&a, &b);
	else
		ft_big_sort(&a, &b, argc);
/* 	printf("\n"); */
/* 	t_list *current_sorted_b = b;
	while (current_sorted_b != NULL)
	{
		printf("after sorting stack B:  %d\n", current_sorted_b->value);
		current_sorted_b = current_sorted_b->next;
	}
	printf("----\n");
	t_list *current_sorted_a = a;
	while (current_sorted_a)
	{
		printf("after sorting stack A:  %d\n", current_sorted_a->value);
		current_sorted_a = current_sorted_a->next;
	} */
	return (0);
}
