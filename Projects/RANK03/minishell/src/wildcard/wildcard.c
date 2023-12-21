/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:53:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 19:38:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	wild_question_mark(char *path, char *pattern)
{
	return (*path && wild_match(path + 1, pattern + 1));
}

int	wild_asterisk(char *path, char *pattern)
{
	if (wild_match(path, pattern + 1))
		return (1);
	return (*path && wild_match(path + 1, pattern));
}

int	wild_brakets(char *path, char **pattern, int match, int invert)
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
	return ((match ^ invert) && wild_match(path + 1, *pattern + 1));
}

int	wild_match(char *path, char *pattern)
{
	if (!*pattern)
		return (!*path);
	if (*pattern == '?')
		return (wild_question_mark(path, pattern));
	if (*pattern == '*')
		return (wild_asterisk(path, pattern));
	if (*pattern == '[')
		return (wild_brakets(path, &pattern, 0, 0));
	if (*pattern == '/')
		return (*path == '/' && wild_match(path + 1, pattern + 1));
	return (*path == *pattern && wild_match(path + 1, pattern + 1));
}
