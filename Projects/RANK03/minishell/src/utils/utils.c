/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:37:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*retkey(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '\'' || str[i] == '"')
			i += skip(&str[i + 1], str[i]) + 1;
		i++;
	}
	if (str[i] == '\0')
		return (ft_strdup(str));
	while (str[i] && str[i] != '=')
		i++;
	return (ft_substr(str, 0, i));
}

char	*retval(char *str)
{
	int		start;

	start = 0;
	while (str[start] && str[start] != '=')
	{
		if (str[start] == '\'' || str[start] == '"')
			start += skip(&str[start + 1], str[start]) + 1;
		start++;
	}
	if (str[start] == '\0')
		return (NULL);
	start++;
	return (ft_strdup(str + start));
}

int	ft_strspn(char *str1, char *str2)
{
	char	*s1;
	int		count;

	count = 0;
	s1 = str1;
	while (*s1 != '\0' && ft_strchr(str2, *s1) != NULL)
	{
		count++;
		s1++;
	}
	return (count);
}

int	ft_strcspn(char *str1, char *str2)
{
	char	*s1;
	int		count;

	s1 = str1;
	count = 0;
	while (*s1 != '\0' && ft_strchr(str2, *s1) == NULL)
	{
		count++;
		s1++;
	}
	return (count);
}

char	*ft_strtok(char *s, char *sep)
{
	static char	*p;

	if (!s)
	{
		s = p;
		if (!s)
			return (NULL);
	}
	s += ft_strspn(s, sep);
	if (!*s)
		return (p = 0);
	p = s + ft_strcspn(s, sep);
	if (*p)
	{
		*p = 0;
		p++;
	}
	else
		p = 0;
	return (s);
}
