/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/11 16:51:56 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* to prevent the pointer from pointing to invalid memory after deallocation */
void	ft_free_stack(char **argv)
{
	if (*argv)
		free(*argv);
	*argv = NULL;
}

/* is called when recieves 1 as an argument indicating an error */
void	ft_exit(int status)
{
	write (1, "Error >(\n", 9);
	exit (status);
}

/* counts the argc in case the elements are pased in " " */
int	new_argc(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		i++;
	return (i);
}

/* filling the stack a */
void	ft_locate(t_list *a, int argc, char **argv)
{
	int		i;
	int		saver;

	i = 1;
	saver = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = new_argc(argv);
		i = 0;
	}
	if (ft_valid_nb(argv, argc, i))
	{
		a->value = ft_atoi(argv[i]);
		i++;
		while (argv[i])
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	}
	ft_addindex(&a, argc - 1, argv, saver);
	if (argc == 2)
		ft_free_stack(argv);
}

/* depending on how many elements are, chose a sorting algorithm */
void	ft_small_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(*a);
	}
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b, 1);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
}

/* void	delete_last_element(t_list **stack)
{
	t_list	*current;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	free(current->next);
	current->next = NULL;
} */

/* declare 2 stacks */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (-1);
	a = ft_lstnew(0);
	//b = ft_lstnew(0);
	ft_locate(a, argc, argv);

	t_list *current_a = a;
	while (current_a)
	{
		printf("before sorting: %d\n", current_a->value);
		current_a = current_a->next;
	}

	t_list *current_a_index = a;
	while (current_a_index != NULL)
	{
		printf("index: %d\n", current_a_index->index);
		current_a_index = current_a_index->next;
	}
	printf("\n");
	if (a_is_sorted(a) == 1)
	{
		free (a);
		//free (b);
		return (0);
	}
	if (ft_lstsize(a) < 6)
		ft_small_sort(&a, &b);
	else
		ft_big_sort(&a, &b, argc);
	printf("\n");
/* 	delete_last_element(&b); */
	t_list *current_sorted_b = b;
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
	}
	return (0);
}
