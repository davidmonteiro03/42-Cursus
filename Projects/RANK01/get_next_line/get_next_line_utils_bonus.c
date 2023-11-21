/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:54:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 14:42:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str++ == (char)c)
			return ((char *)(--str));
	}
	if (*str == (char)c)
		return ((char *)(str));
	return ((char *)0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned char	*s;
	unsigned int	buffer;

	buffer = nmemb * size;
	mem = malloc(buffer);
	if (!mem)
		return ((void *)0);
	s = (unsigned char *)mem;
	while (buffer-- > 0)
		*s++ = 0;
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	while (*s1)
		str[j++] = *s1++;
	while (*s2)
		str[j++] = *s2++;
	str[j] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
