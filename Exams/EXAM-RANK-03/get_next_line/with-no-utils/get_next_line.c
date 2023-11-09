/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:22:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:14:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024

#endif

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)(--s));
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)0);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned int	buffer;
	unsigned char	*s;

	buffer = nmemb * size;
	mem = malloc(buffer);
	if (!mem)
		return ((void *)0);
	s = (unsigned char *)mem;
	while (buffer-- > 0)
		*s++ = 0;
	return (mem);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] && count < len)
	{
		if (i >= start)
			count++;
		i++;
	}
	str = (char *)malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = 0;
	while (count-- > 0)
		str[count] = s[count + start];
	return (str);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

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
