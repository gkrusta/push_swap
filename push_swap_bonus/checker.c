/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:26:43 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 14:17:10 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_is_sorted(char *instruction, t_list **a, t_list **b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(*a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(*b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(*a, *b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(a, bcmp);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(a, b);
	else
		free(instruction);
}

void	read_from_output(t_list **a, t_list **b)
{
	char	*std_output;

	std_output = get_next_line(0);
	while (std_output)
	{
		ft_is_sorted(std_output, a, b);
		free (std_output);
		std_output = get_next_line(0);
	}
	free(std_output);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**stack;

	if (argc < 2)
		return (0);
	ft_locate(a, argc, argv);
	if (a_is_sorted(a) == 1)
	{
		free (a);
		return (0);
	}
	if (ft_lstsize(a) < 6)
		ft_small_sort(&a, &b);
	else
		ft_big_sort(&a, &b, argc);
	read_from_output(&a, &b);
	if (a_is_sorted(a) == 1 && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
