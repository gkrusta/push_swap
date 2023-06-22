/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:26 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/22 12:48:16 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* cheking if the numberes are type int */
int	overflow(char *str)
{
	long	n;

	n = ft_long_atoi(str);
	if (n >= INT_MIN && n <= INT_MAX)
		return (1);
	return (0);
}
/* checking if none of the numbers repeat */
int	find_doubles(char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	while (argv[i])
	{
		tmp = ft_strdup(argv[i]);
		j = 0;
		while (argv[i])
		{
			if (i == j)
				j++;
			else if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				ft_free_stack(argv[i]);
				ft_exit(1);
			}
			else
				j++;
		}
		ft_free_stack(argv[i]);
		i++;
	}
	return (1);
}

/* checking if the numbers are already in order */
int	a_is_sorted(t_stack *lst)
{
	t_stack	*head;

	head = lst;
	if (!lst)
		return (-1);
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

/* checking if the elements consist of digits and 1 possible sign */
int	only_numbers(char **argv)
{
	char	**av;
	int		i;
	int		j;

	av = argv;
	i = 0;
	while (av[i])
	{
		if (overflow(av[i]) == 1)
			return (0);
		j = 0;
		if ((av[i][j] == '+' || av[i][j] == '-') && av[i][j + 1] != '\0')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_exit(1);
			j++;
		}
		i++;
	}
	return (1);
}

/*  */
int	ft_valid_nb(char **new)
{
	if (only_numbers(new) != 1)
		ft_exit(1);
	if (find_doubles(new) != 1)
		ft_exit (1);
	return (1);
}
