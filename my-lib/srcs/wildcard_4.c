/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:53:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 13:07:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_4.h"

int	wildqst(char *path, char *pattern)
{
	return (*path && wildcmp(path + 1, pattern + 1));
}

int	wildast(char *path, char *pattern)
{
	if (wildcmp(path, pattern + 1))
		return (1);
	return (*path && wildcmp(path + 1, pattern));
}

int	wildsqb(char *path, char **pattern, int match, int invert)
{
	(*pattern)++;
	if (**pattern == '!')
	{
		invert = 1;
		(*pattern)++;
	}
	while (**pattern != ']')
	{
		if (!**pattern)
			return (0);
		if (*(*pattern + 1) == '-' && *(*pattern + 2) != ']')
		{
			match = match || (*path >= **pattern && *path <= *(*pattern + 2));
			*pattern += 3;
		}
		else
		{
			match = match || *path == **pattern;
			(*pattern)++;
		}
	}
	return ((match ^ invert) && wildcmp(path + 1, *pattern + 1));
}

int	wildcmp(char *path, char *pattern)
{
	if (!*pattern)
		return (!*path);
	if (*pattern == '?')
		return (wildqst(path, pattern));
	if (*pattern == '*')
		return (wildast(path, pattern));
	if (*pattern == '[')
		return (wildsqb(path, &pattern, 0, 0));
	return (*path == *pattern && wildcmp(path + 1, pattern + 1));
}
