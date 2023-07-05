/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/05 13:36:11 by gkrusta          ###   ########.fr       */
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

/* sort the elements in ascending order */
char	**ft_sort_params(int argc, char **argv, int check)
{
	int		i;
	int		j;
	char	*temp;

	i = check;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
/* 	i = 0;
	while (i++ < argc)
		ft_putstr_fd(argv[i], 1); */
	return (argv);
}

/* add index to the each element in ascending order*/
void	ft_addindex(t_list **a, int argc, char **argv)
{
	int		x;
	int		check;
	t_list	*tmp;

	tmp = *a;
	if (argv[0] == NULL)
		check = 1;
	else
		check = 0;
	ft_sort_params(argc, argv, check);
	printf ("addinedx  %d\n\n", tmp->value);
	while (tmp)
	{
		x = check;
		while (x < argc)
		{
			if (ft_atoi(argv[x]) == ((tmp)->value))
				(tmp)->index = x;
			x++;
		}
		(tmp) = (tmp)->next;
	}
}

int	new_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

/* filling the stack a */
void	ft_locate(t_list *a, int argc, char **argv)
{
	int		i;
	t_list	*fill_a;
/* 	char	**new;
 */
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = new_argc(argv);
		i = 0;
	}
/* 	else
		new = &argv[1]; */
	if (ft_valid_nb(argv, argc))
	{
		a->value = ft_atoi(argv[i]);
		i++;
		while (argv[i])
		{
			fill_a = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(&a, fill_a);
			i++;
		}
	}
	ft_addindex(&a, argc, argv);
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
		sort_4(a, b);
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
		ft_small_sort(&a, &b);
		printf("\n");
		t_list *current_sorted_a = a;
		while (current_sorted_a)
		{
			printf("after sorting: %d\n", current_sorted_a->value);
			current_sorted_a = current_sorted_a->next;
		}
	}
	return (0);
}
