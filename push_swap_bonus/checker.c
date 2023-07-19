/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:26:43 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 12:41:10 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	instruction_read(char *instruction, t_list **a, t_list **b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(*a, 1);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(*b, 1);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(*a, *b, 1);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(a, 1);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(b, 1);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(a, 1);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(b, 1);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(a, b, 1);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(a, b, 1);
	else
		free (instruction);
}

void	read_from_output(t_list **a, t_list **b)
{
	char	*output;

	output = get_next_line(0);
	while (output)
	{
		instruction_read(output, a, b);
		free (output);
		output = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	ft_locate(&a, &argc, argv);
	if (a_is_sorted(a) == 1)
	{
		ft_free_arguments(&a);
		return (0);
	}
	read_from_output(&a, &b);
	if (a_is_sorted(a) == 1 && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_arguments(&a);
	return (0);
}
