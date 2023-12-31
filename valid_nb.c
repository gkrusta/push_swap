/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:26 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 17:23:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* cheking if the numberes are type int */
int	overflow(char *str)
{
	long	n;

	n = ft_long_atoi(str);
	if (n >= INT_MIN && n <= INT_MAX)
		return (0);
	return (1);
}

/* checking if none of the numbers repeat */
int	find_doubles(char **argv, int i, int nb)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (0);
		i++;
	}
	return (1);
}

/* checking if the numbers are already in order */
int	a_is_sorted(t_list *lst)
{
	t_list	*head;

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
int	only_numbers(char **argv, int i)
{
	char	**av;
	int		j;

	av = argv;
	while (av[i])
	{
		if (overflow(av[i]) == 1)
			return (0);
		j = 0;
		if (argv[i][j] == '\0')
			return (0);
		if ((av[i][j] == '+' || av[i][j] == '-') && av[i][j] != '\0')
			j++;
		if ((av[i][j] == '+' || av[i][j] == '-') && av[i][j + 1] != '\0')
			return (0);
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* checking if numbers are valid */
int	ft_valid_nb(char **new, int i)
{
	if (only_numbers(new, i) != 1)
		ft_exit(1);
	while (new[i + 1]) // the last element will be checked in find_doubles()
	{
		if (find_doubles(new, i, ft_atoi(new[i])) != 1)
			ft_exit (1);
		i++;
	}
	return (1);
}
