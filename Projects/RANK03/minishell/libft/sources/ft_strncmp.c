/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:21:04 by preis-ne          #+#    #+#             */
/*   Updated: 2024/07/08 10:57:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strncmp -- compare two strings at most 'n bytes.
**
**SYNOPSIS: int	ft_strncmp(const char *s1, const char *s2, size_t n);
**
**DESCRIPTION: The ft_strncmp() function compares two strings s1 and s2 the
**	first (at most) n bytes of s1 and s2. It returns an integer less than,
**	equal to, or greater than zero if s1 is found, respectively, to be less
**	than, to match or to be greater than s2.
**
**PARAMETERS:	s1: first string to be compare
**		s2: second string to compare;
**		n: bytes to be compare.
**
**RETURN VALUE:	Returns an integer less than, equal to, or greater than zero
**	if the first 'n' bytes of 's1' is found, respectively, to be less than
**	to match, or to be grater than 's2'
**
**ERRORS: \NA
**
**FUNCTION: \NA*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (n > ++i && (s1[i] != '\0' || s2[i] != '\0'))
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
*/
/*
int	main(void)
{
	char	s1[] = "pois";
	char	s2[] = "pa";

	printf("%d\n", ft_strncmp(s1,s2,2));

	printf("%d", strncmp(s1,s2,2));
}
*/
