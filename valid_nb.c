/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:22:26 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/19 16:45:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	is_number(char *str)
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
}

int	a_is_sorted(t_stack **lst)
{
	t_list	*head;

	head = *lst;
	if (!*lst)
		return (-1);
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
