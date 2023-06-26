/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/26 18:58:06 by gkrusta          ###   ########.fr       */
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

/* add index to the each element */
void	ft_addindex(t_list *a)
{
	int		index;
	t_list	*current;

	index = 0;
	current = a;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

/* filling the stack a */
void	ft_locate(t_list *a, int argc, char **argv)
{
	int		i;
	t_list	*fill_a;
	char	**new;

	i = 0;
	if (argc == 2)
		new = ft_split(argv[1], ' ');
	else
	{
		new = &argv[1];
	}
	if (ft_valid_nb(new, argc))
	{
		a->value = ft_atoi(new[i]);
		i++;
		while (new[i])
		{
			fill_a = ft_lstnew(ft_atoi(new[i]));
			ft_lstadd_back(&a, fill_a);
			i++;
		}
	}
	ft_addindex(a);
	if (argc == 2)
		ft_free_stack(new);
}

/* depending on how many elements are, chose a sorting algorithm */
void	ft_small_sort(t_list *a)
{
	if (ft_lstsize(a) == 2)
	{
		if (a->value > a->next->value)
			sa(a);
	}
	if (ft_lstsize(a) == 3)
	{
		sort_3(a);
	}
}

/* declare 2 stacks */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (-1);
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	if (!b || !a)
		return (1);
	ft_locate(a, argc, argv);

	t_list *current_a = a;
	while (current_a)
	{
		printf("before sorting: %d\n", current_a->value);
		current_a = current_a->next;
	}

	t_list *current_a_index = a;
	while (current_a_index)
	{
		printf("index: %d\n", current_a_index->index);
		current_a_index = current_a_index->next;
	}
	printf("\n");
	if (a_is_sorted(a) == 1)
	{
		free (a);
		free (b);
		return (0);
	}
	if (ft_lstsize(a) < 6)
	{
		ft_small_sort(a);
		t_list *current_sorted_a = a;
		while (current_sorted_a)
		{
			printf("after sorting: %d\n", current_sorted_a->value);
			current_sorted_a = current_sorted_a->next;
		}
	}
	return (0);
}
