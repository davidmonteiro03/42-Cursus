/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:11:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char c)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	size;

	strs = malloc((count(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			if (!ft_strchr(s, c))
				size = ft_strlen(s);
			else
				size = ft_strchr(s, c) - s;
			strs[i++] = ft_substr(s, 0, size);
			s = s + size;
		}
		while (*s == c && *s)
			s++;
	}
	strs[i] = 0;
	return (strs);
}
