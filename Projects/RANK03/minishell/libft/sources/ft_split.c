/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:20:32 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/18 13:58:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* NAME: ft_split() --- split a string into an array of words
**
**SYNOPSIS: char	**ft_split(char const *s, char c);
**
**DESCRIPTION: Allocates with malloc() and returns an array of strings obtained
**	by splitting 's' using the character 'c' as a delimiter. The array must
**	end with a NULL pointer.
**
**PARAMETERS:	s: The string to be split.
**		c: The delimiter character.
**
**RETURN VALUE: The array of the new string resulting from the split.
**	NULL if the allocation fails.
**
**ERRORS: \NA
**
**EXPLANATION:
**
**FUNCTIONS: malloc(), free(). */
static int	ft_words(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static size_t	ft_lenwords(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static char	**ft_break(char const *s, char c, char **strs, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		strs[i] = ft_substr(s, j, ft_lenwords(&s[j], c));
		if (!strs[i])
		{
			ft_free(strs);
			return (0);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (0);
	words = ft_words(s, c);
	if (!words)
		return (0);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (0);
	split = ft_break(s, c, split, words);
	return (split);
}
/*
 int	main(void)
{
	char	**split;
	int		i;

//	split = ft_split("", 'o');
	split = ft_split("|c|o|rta es|ta |merda|", '|');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

*/
/*
static int	ft_words(char const *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			if (s[i] != c && j++ == 0)
				n++;
			i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (n);
}

static int	ft_free(char *str, int k)
{
	while (k >= 0)
		free(str[k--]);
	free(str);
	return (0);
}

static char	**ft_copy(char const *s, char c, char **str, int i)
{
	int	k;
	int	j;
	int	n;

	k = 0;
	while (s[i])
	{
		j = 0;
		n = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] != 0)
		{
			n++;
			if (s[i + 1 ] == c || s[i + 1] == '\0')
			{
				str[k] = malloc((n + 1) * sizeof(char));
				if (!str[k])
					ft_free(str, k);
				while (n > 0)
					str[k][j++] = s[(i + 1) - n--];
				str[k++][j] = 0;
			}
			i++;
		}
	}
	str[k] = 0;
	return (str);
}


char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	n;
	char	**str;
	int	k;

	k = 0;
	i = 0;
	n = ft_words(s,c);
	str = (char **)malloc((n + 1) * sizeof(char*));
	if (!str)
		return(0);
	return(ft_copy(s,c, str,i));
}
*/
