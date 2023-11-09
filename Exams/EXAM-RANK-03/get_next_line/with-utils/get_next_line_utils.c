/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:03:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
