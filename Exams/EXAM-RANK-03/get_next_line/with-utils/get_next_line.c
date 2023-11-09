/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:22:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:07:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_joinfree(char *str, char *buff)
{
	char	*tmp;

	tmp = gnl_strjoin(str, buff);
	free(str);
	return (tmp);
}

char	*read_file(int fd, char *buffer)
{
	char	*buf;
	int		sz;

	if (!buffer)
		buffer = gnl_calloc(1, 1);
	buf = gnl_calloc(1, BUFFER_SIZE + 1);
	sz = 1;
	while (!gnl_strchr(buffer, '\n') && sz > 0)
	{
		sz = read(fd, buf, BUFFER_SIZE);
		if (sz <= 0)
			break ;
		buffer = gnl_joinfree(buffer, buf);
		free(buf);
		buf = gnl_calloc(1, BUFFER_SIZE + 1);
	}
	free(buf);
	if (sz < 0 || !*buffer)
		return (free(buffer), NULL);
	return (buffer);
}

char	*next_buffer(char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		tmp = gnl_strjoin(buffer + i, "");
		free(buffer);
		return (tmp);
	}
	tmp = gnl_strjoin(buffer + i + 1, "");
	free(buffer);
	return (tmp);
}

char	*next_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (gnl_substr(buffer, 0, i));
	return (gnl_substr(buffer, 0, i + 1));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	buffer = next_buffer(buffer);
	return (line);
}
