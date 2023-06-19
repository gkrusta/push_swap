/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/19 17:40:07 by gkrusta          ###   ########.fr       */
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

char	**ft_fill_stack(t_stack *cur, int argc, char **argv)
{
	if (argc == 2)
		cur->split = ft_split(argv[1], ' ');
	
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

/* 	a = malloc(sizeof() * );
	b = malloc(sizeof() * ); */

}