/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:32 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/21 15:52:06 by gkrusta          ###   ########.fr       */
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

/* add index to the each element */
void	ft_addindex(t_list **fill_a)
{
	int		index;
	t_list	*current;

	index = 0;
	current = *fill_a;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

/* filling the stack a */
t_list	**ft_locate(t_list **a, int argc, char **argv)
{
	int		i;
	t_list	*fill_a;
	char	**new;

	i = 0;
	if (argc == 2)
		new = ft_split(argv[1], ' ');
	else
	{
		new = argv;
		i = 1;
	}
	while (new[i])
	{
		fill_a = ft_lstnew(ft_atoi(new[i]));
		ft_lstadd_back(a, fill_a);
		i++;
	}
	ft_addindex(a);
	if (argc == 2)
		free (argv);
	return (a);
}

/* declare 2 stacks */
int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (-1);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	a = ft_locate(a, argc, argv);
	ft_valid_nb(a, argc, argv);

}
