/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:46:53 by gkrusta           #+#    #+#             */
/*   Updated: 2023/06/19 16:46:45 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

/* libraries used */
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}				t_stack;

#endif