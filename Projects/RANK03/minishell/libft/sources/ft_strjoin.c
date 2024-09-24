/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:48:30 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/03 06:06:53 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strjoin --- concatenate two strings
**
**SYNOPSIS: char	*ft_strjoin(char const *s1, char const *s2);
**
**DESCRIPTION: Allocates with malloc and returns a new string, which is the
**	result of the concatenation of 's1' and 's2'.
**
**PARAMETERS: 	s1: The prefix string
**		s2: The suffix string
**
**RETURN VALUE:	Returns the new string
**		NULL if the allocation fails
**
**ERRORS:	\NA
**
**EXPLANATION: ft_strjoin() allocate the require memory for both of the two 
**	strings that are pass as parameters and a NUL-terminating character.
**	The result is a concatenated string with 's1' being the first string
**	and 's2' the second one.
**
**FUNTION: malloc()*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char	*ptr = "coisa";
	char	*ptr1 = "pois";

	printf("%s", ft_strjoin(ptr, ptr1));
}*/
