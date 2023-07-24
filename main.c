/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/24 12:35:04 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (-1);
	a = NULL;
	b = NULL;
	ft_locate(&a, &argc, argv);
	if (a_is_sorted(a) == 1 || ft_lstsize(a) == 1)
	{
		ft_free_arguments(&a);
		return (0);
	}
	if (ft_lstsize(a) < 6)
		ft_small_sort(&a, &b);
	else
		ft_big_sort(&a, &b, argc);
	ft_free_arguments(&a);
	return (0);
}
