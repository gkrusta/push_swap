/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/20 15:29:58 by gkrusta          ###   ########.fr       */
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
	write (1, "Error\n", 6);
	exit (status);
}

/* filling the stack a */
char	**ft_locate(t_stack **a, int argc, char **argv)
{
	int		i;
	t_stack	**fill_a;

	if (argc == 2)
		a = ft_split(argv[1], ' ');
	else
		a = &argv[1];
	while (argv[i] != '\0')
	{
		fill_a = ft_lstadd_back(a, argv[i]);
		i++;
	}
	if (argc == 2)
		free (argv);
	return (fill_a);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (-1);
	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	ft_locate(a, argc, argv);
}
