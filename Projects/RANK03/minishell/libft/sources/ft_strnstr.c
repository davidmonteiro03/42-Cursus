/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <preis-ne@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:55:43 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/04 06:32:10 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strnstr --- locate a substring in a string
**
**SYNOPSIS: char *ft_strnstr(const char *big, const char *little, size_t len);
**
**DESCRIPTION: The ft_strnstr() function locates the first occurrence of the
**	null-terminated string 'little' in the string 'big', where not more
**	than 'len' characters are searched. Characters that appear after a '\0'
**	character are not searched.
**
**PARAMETERS:	big: string to be scanned;
**		litte: string to be searched in;
**		len: size of 'big' to be search.
**
**RETURN VALUE: If 'little' is an empty string, 'big' is returned;
**		If 'little' occurs nowhere in 'big', NULL is returned;
**		Otherwise a pointer to the FIRST characher of the FIRST 
**	occurence of 'little' is returned.
**
**ERRORS: \NA;
**
**FUNCTIONS: \NA*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return (&((char *)big)[i]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && j + i < len)
		{
			if (little[j + 1] == '\0')
				return (&((char *)big)[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{

		printf("%s", ft_strnstr(argv[1], argv[2], argv[3][0]));
	}
}
*/
