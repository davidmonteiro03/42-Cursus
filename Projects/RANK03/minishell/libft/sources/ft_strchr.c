/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 03:16:24 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/04 06:47:22 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strchr -- locate a character in string
**
**SYNOPSIS: char *ft_strchr(const char *ptr, int i);
**
**DESCRIPTION: The ft_strchr() function returns a pointer to the FIRST occurence
**	of the character 'i' in the string 'ptr'. 
**
**PARAMETERS:	i: character to be found;
		ptr: string to search;
**
**RETURN VALUES: Returns a pointer to the mached character or NULL if the 
**		character is not found. The terminating null byte us considered
**	
**ERRORS: \NA 
**
**FUNCTIONS: \NA */
char	*ft_strchr(const char *ptr, int i)

{
	int	n;

	n = -1;
	while (ptr[++n] != (char)i)
		if (ptr[n] == '\0')
			return (0);
	return ((char *)&ptr[n]);
}
/*
int	main(void)
{
	char	arr[] = "coisa";
	int	i = 'i';

	printf("%s\n", ft_strchr(arr, i));

	printf("%s\n", strchr(arr, i));
}
*/
