/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:31:10 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/22 13:56:38 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_find_char(int fd, char *str_ac)
{
	char	*temp;
	int		read_return;

	if (!str_ac)
		str_ac = ft_calloc(1, sizeof(char));
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_return = 1;
	while (read_return > 0)
	{
		read_return = read(fd, temp, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[read_return] = '\0';
		str_ac = ft_concat_free(str_ac, temp);
		if (ft_strchr(temp, '\n') == 1)
			break ;
	}
	free(temp);
	return (str_ac);
}

char	*ft_concat_free(char *str_ac, char *temp)
{
	char	*joined_str;

	joined_str = ft_strjoin(str_ac, temp);
	free(str_ac);
	return (joined_str);
}

char	*ft_get_line(char *str_ac)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	if (str_ac[i] == '\0')
		return (NULL);
	len = ft_line_len(str_ac) + 1;
	if (!len)
		return (NULL);
	line = ft_calloc(len, sizeof(char));
	while (str_ac[i] != '\0' && str_ac[i] != '\n')
	{
		line[i] = str_ac[i];
		i++;
	}
	if (str_ac[i] != '\0' && str_ac[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_clear_memory(char *str_ac)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	while (str_ac[i] != '\n' && str_ac[i])
		i++;
	if (str_ac[i] == '\0')
	{
		free(str_ac);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(str_ac) - i + 1, sizeof(char));
	i++;
	while (str_ac[i] != '\0')
		new_line[j++] = str_ac[i++];
	free(str_ac);
	if (new_line[0] == '\0')
	{
		free(new_line);
		return (NULL);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*str_ac[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		if (str_ac[fd] != NULL)
		{
			free(str_ac[fd]);
			str_ac[fd] = NULL;
		}
		return (NULL);
	}
	str_ac[fd] = ft_find_char(fd, str_ac[fd]);
	line = ft_get_line(str_ac[fd]);
	str_ac[fd] = ft_clear_memory(str_ac[fd]);
	return (line);
}
