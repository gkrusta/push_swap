/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:03:10 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 19:05:16 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* returns the minimum value */
int	get_min(t_list *a)
{
	t_list	*current;
	int		min;

	current = a;
	min = INT_MAX;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

/* returns the next minimum value */
int	get_next_min(t_list *a, int min)
{
	t_list	*current;
	int		next_min;

	current = a;
	next_min = INT_MAX;
	while (current != NULL)
	{
		if (current->value > min && current->value < next_min)
			next_min = current->value;
		current = current->next;
	}
	return (next_min);
}

/* sorts the elements in ascending order */
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
	return (argv);
}

/* puts the index in case the elements are pased in " " */
void	ft_addindex_str(t_list **a, int argc, char **argv)
{
	int		x;
	int		i;
	t_list	*tmp;

	tmp = *a;
	x = 0;
	i = 1;
	ft_sort_params(argc, argv, x);
	while (tmp)
	{
		x = 0;
		i = 1;
		while (x < argc)
		{
			if (ft_atoi(argv[x]) == ((tmp)->value))
				(tmp)->index = i;
			x++;
			i++;
		}
		(tmp) = (tmp)->next;
	}
}

/* add index to the each element in ascending order*/
void	ft_addindex(t_list **a, int argc, char **argv, int saver)
{
	int		x;
	t_list	*tmp;

	tmp = *a;
	x = 1;
	if (saver == 2)
		ft_addindex_str(a, argc, argv);
	else
	{
		ft_sort_params(argc, argv, x);
		while (tmp)
		{
			x = 1;
			while (x < argc)
			{
				if (ft_atoi(argv[x]) == ((tmp)->value))
					(tmp)->index = x;
				x++;
			}
			(tmp) = (tmp)->next;
		}
	}
}
