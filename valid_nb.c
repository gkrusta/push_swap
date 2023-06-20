/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:26 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/20 19:02:13 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

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

int	a_is_sorted(t_list **lst)
{
	t_list	*head;

	head = *lst;
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

int	only_numbers(char **argv)
{
	char	**av;
	int		i;
	int		j;

	av = argv;
	while (av[i])
	{
		if (!argv[i])
			return (0)
		while (av[i][j])
		{
			j++;
		}
		i++;
	}
}

int	ft_valid_nb(t_list **a, int argc, char **argv)
{
	if (a_is_sorted(a) == 1 || only_numbers(argv) == 0)
	{
		free (a);
		free (b);
		ft_exit (1);
	}
	else if ()
}
