/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:54:34 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/30 09:40:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_jointfree(char *str, char *buff)
{
	char	*temp;

	temp = gnl_strjoin(str, buff);
	free(str);
	return (temp);
}

char	*read_file(int fd, char	*buffer)
{
	char	*buf;
	int		bytes;

	if (!buffer)
		buffer = gnl_calloc(1, 1);
	buf = gnl_calloc(1, BUFFER_SIZE + 1);
	bytes = 1;
	while (!gnl_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0 || bytes < 0)
			break ;
		buffer = gnl_jointfree(buffer, buf);
		free(buf);
		buf = gnl_calloc(1, BUFFER_SIZE + 1);
	}
	free(buf);
	if (bytes < 0 || !*buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*next_buffer(char	*buffer)
{
	char	*temp;
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		temp = gnl_strjoin(buffer + i, "");
		free(buffer);
		return (temp);
	}
	temp = gnl_strjoin(buffer + i + 1, "");
	free(buffer);
	return (temp);
}

char	*next_line(char	*buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (gnl_substr(buffer, 0, i));
	return (gnl_substr(buffer, 0, i + 1));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SIZE];
	char		*line;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = next_line(buffer[fd]);
	buffer[fd] = next_buffer(buffer[fd]);
	return (line);
}
