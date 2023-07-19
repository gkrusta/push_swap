/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:16:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/19 19:03:58 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/* is called when recieves 1 as an argument indicating an error */
void	ft_exit(int status)
{
	write (1, "Error\n", 6);
	exit (status);
}

/* counts the argc in case the elements are pased in " " */
int	new_argc(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		i++;
	return (i);
}

void	ft_free_argv(char **str, int argc)
{
	while (argc-- > 0)
		free(str[argc]);
	free (str);
}

/* filling the stack a */
void	ft_locate(t_list **a, int *argc, char **argv)
{
	int		i;
	int		saver;

	i = 1;
	saver = *argc;
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*argc = new_argc(argv);
		i = 0;
	}
	if (ft_valid_nb(argv, i))
	{
		while (argv[i])
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		ft_addindex(a, *argc, argv, saver);
	}
	if (saver == 2)
		ft_free_argv(argv, *argc);
}

void	ft_free_arguments(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}
