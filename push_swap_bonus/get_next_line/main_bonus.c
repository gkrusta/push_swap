/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:09:24 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/22 13:56:51 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

#define FD_COUNT 2

int	main(void)
{
	int		fds[FD_COUNT];
	int		i;
	char	*line;

	//open the files
	fds[0] = open("example.txt", O_RDONLY);
	fds[1] = open("example2.txt", O_RDONLY);

	//read from the each fd
	i = 0; // 1st call 
	while (i < FD_COUNT)
	{
		line = get_next_line(fds[i]);
		printf("1st call result from the fd %d: %s\n", fds[i], line);
		i++;
	}
	i = 0; // 2nd call
	while (i < FD_COUNT)
	{
		line = get_next_line(fds[i]);
		printf("2nd call result from the fd %d: %s\n", fds[i], line);
		i++;
	}
	i = 0; // 3rd call
	while (i < FD_COUNT)
	{
		line = get_next_line(fds[i]);
		printf("3rd call result from the fd %d: %s\n", fds[i], line);
		i++;
	}
	return (0);
}
