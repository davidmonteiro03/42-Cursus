/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:38:23 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/16 18:06:58 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_left_string(char *buffer)
{
	char	*left_string;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	left_string = ft_strdup(&buffer[i]);
	if (!left_string)
		return (free(buffer), buffer = NULL, NULL);
	free(buffer);
	buffer = NULL;
	return (left_string);
}

char	*ft_line(char *buffer, char *line)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *file, char *buffer)
{
	auto char *tmp = 0;
	auto int status = -1;
	while (status != 0)
	{
		status = read(fd, file, BUFFER_SIZE);
		if (status == -1)
			return (free(buffer), buffer = NULL, NULL);
		if (status == 0)
			return (buffer);
		file[status] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
		tmp = buffer;
		buffer = ft_strjoin(tmp, file);
		free(tmp);
		tmp = NULL;
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(file, '\n'))
			return (buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FILES];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > FILES || BUFFER_SIZE <= 0)
		return (NULL);
	auto char *file = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file)
	{
		if (buffer[fd] != NULL)
			return (free(buffer[fd]), buffer[fd] = NULL, NULL);
		return (NULL);
	}
	buffer[fd] = ft_read(fd, file, buffer[fd]);
	free(file);
	file = NULL;
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd], line);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_left_string(buffer[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char *line;

	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/
