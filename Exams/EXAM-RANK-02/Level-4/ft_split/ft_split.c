/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:21:08 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 11:19:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

size_t	ft_count(char *str)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		end = i;
		if (end > start)
			count++;
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	return (count);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	tmplen;
	size_t	i;

	if (!str)
		return (NULL);
	tmplen = 0;
	while (str[tmplen])
		tmplen++;
	if (start >= tmplen)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (i < len && str[start])
		result[i++] = str[start++];
	return (result);
}

char	**ft_destroy(char *str, size_t i, size_t j, size_t len)
{
	char	**result;
	size_t	start;
	size_t	end;

	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = NULL;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		end = i;
		if (end > start)
			result[j++] = ft_substr(str, start, end - start);
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	return (result);
}

char	**ft_split(char *str)
{
	char	**result;
	size_t	len;

	result = NULL;
	if (!str || !*str)
		return (NULL);
	len = ft_count(str);
	result = ft_destroy(str, len, 0, 0);
	if (!result)
		return (NULL);
	return (result);
}
