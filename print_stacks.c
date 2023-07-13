/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:26:56 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 14:10:18 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_format(char c)
{
	if (c == 'e')
		ft_printf("          ");
	if (c == 'b')
		ft_printf("   * list a ** list b *\n\n");
	if (c == 'n')
		ft_printf("\n");
}

t_list	*lst_print_node(t_list *lst)
{
	int	space;
	int	num_len;

	space = 10;
	num_len = ft_strlen(ft_itoa(lst->value));
	while (space > num_len)
	{
		ft_printf(" ");
		space--;
	}
	ft_printf("%i", lst->value);
	lst = lst->next;
	return (lst);
}

void	lst_print_stacks(t_list **lst_a, t_list **lst_b)
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
	int		line;

	a = *lst_a;
	b = *lst_b;
	size_a = ft_lstsize(*lst_a);
	size_b = ft_lstsize(*lst_b);
	line = size_a;
	if (size_a < size_b)
		line = size_b;
	while (line > 0)
	{
		if (size_a >= line)
			a = lst_print_node(a);
		else
			print_format('e');
		if (size_b >= line)
			b = lst_print_node(b);
		print_format('n');
		line--;
	}
	print_format('b');
}
