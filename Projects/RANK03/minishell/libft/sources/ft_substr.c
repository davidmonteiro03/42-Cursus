/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 04:26:54 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/03 04:41:33 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* NAME: ft_substr --- extract a substring from a string 
**
**SYNOPSIS: char *ft_substr(char const *s, unsigned int start, size_t len);
**
**DESCRIPTION: Allocates with malloc() and returns a substring from the 
**	string 's'. The substring begins at index 'start' and is of maximum
**	size 'len'.
**
**PARAMETERS: 	s: the string from which to create the substring.
**		start: The start index of the substring in the string 's'
**		len: The maximum lenght of the substring.
**
**RETURN VALUE: Returns the substring. NULL if the allocation fails.
**
**ERRORS: \NA
**
**EXPLANATION: ft_substr() returns a substring of the string 's' passed as
**	parameter.
**	$ft_substr("coisa e tal",2,4)
**	$isa 
**FUNTION: malloc()*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	void	*str;
	size_t	lens;
	size_t	i;

	i = -1;
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	if (start + len > lens)
		len = lens - start;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (++i < len)
		((char *)str)[i] = s[start + i];
	((char *)str)[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*ptr = "coisa";
	printf("%s", ft_substr(ptr, 2, 4));
}
*/
