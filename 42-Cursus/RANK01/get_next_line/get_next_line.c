/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:54:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/07 17:02:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_jointfree(char *str, char *buff)
{
	char	*temp;

	temp = ft_strjoin(str, buff);
	free(str);
	return (temp);
}

char	*read_file(int fd, char	*buffer)
{
	char	*buf;
	int		bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buf = ft_calloc(1, BUFFER_SIZE + 1);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0 || bytes < 0)
			break ;
		buffer = ft_jointfree(buffer, buf);
		free(buf);
		buf = ft_calloc(1, BUFFER_SIZE + 1);
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
		temp = ft_strjoin(buffer + i, "");
		free(buffer);
		return (temp);
	}
	temp = ft_strjoin(buffer + i + 1, "");
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
		return (ft_substr(buffer, 0, i));
	return (ft_substr(buffer, 0, i + 1));
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
