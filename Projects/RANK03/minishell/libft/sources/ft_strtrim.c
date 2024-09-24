/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:11:02 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/03 07:26:32 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strtrim --- trims character set from string
**
**SYNOPSIS: char *ft_strtrim(char const *s1, char const *set);
**
**DESCRIPTION: Allocates with malloc() and returns a copy of 's1' with the
**	characters specified in 'set' removed from the beginning and the
**	end of the string.
**
**PARAMETERS:	s1: The string to be trimmed.
**		set: The reference set of characters to trim.
**
**RETURN VALUE: The trimmed string. 
**		Null if the allocation fails.
**
**ERRORS:	\NA
**
**EXPLANATION: The function ft_strtrim() remove the charasters specified in the
**	'set' string from the start and the end of the string 's1', without 
**	removing the characters from the 'set' that are in the middle of 's1'
**	$ft_strtrim(oioiiiicoisaoiiio,oi)
**	$coisa
**
**FUNCTIONS: malloc() */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;

	str = 0;
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > first)
		last--;
	str = ft_calloc(last - first + 1, sizeof(char));
	if (str)
		ft_strlcpy(str, &s1[first], last - first + 1);
	return (str);
}
/*
int main()
{
	printf("%s\n", ft_strtrim("asdpoisasdas", "asd"));
	printf("%s\n", ft_strtrim("oioicoisaioioi", "oi"));
	return 0;
}
*/
