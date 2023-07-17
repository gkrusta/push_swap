/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:16:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/17 19:01:05 by gkrusta          ###   ########.fr       */
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
	if (ft_valid_nb(argv, i))
	{
/* 		a->value = ft_atoi(argv[i]);
		i++; */
		while (argv[i])
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	}
	ft_addindex(&a, argc, argv, saver);
	if (argc == 2)
		ft_free_stack(argv);
}

/* depending on how many elements are, chose a sorting algorithm */
void	ft_small_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(*a, 0);
	}
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b, 1);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
}
