/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <preis-ne@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:50:14 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/09 21:46:55 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_memchr --- scan memory for a character
**
**SYNOPSIS: void	ft_memchr(const void *ptr, int i, size_t n);
**
**DESCRIPTION: The memchr() function scans the initial 'n' bytes of memory area 
**	pointed to by 'ptr' for the first intance of 'i'. Both 'i' and the bytes 
**	of the memory area pointed by 'ptr' are interpreted as UNSIGNED CHAR.
**
**PARAMETERS:	ptr: pointed to string to be scanned;
**		i: char to be found in string
**		n: number of bytes to be scan
**
**RETURN VALUES: Return a pointer to the matching byte or NULL if the character 
**	does not occur in the given memory area.
**
**ERRORS: \NA;
**
**FUNCTIONS: \NA */
void	*ft_memchr(const void *ptr, int i, size_t n)
{
	size_t		k;

	k = 0;
	while (k < n)
	{
		if (((unsigned char *)ptr)[k] == (unsigned char)i)
			return (&((unsigned char *)ptr)[k]);
		k++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
//		puts(ft_memchr("coisa", 53, 32945820934822));
		printf("%p\n", ft_memchr("coisa", 49 , 32945820934822));
		printf("%p", memchr("coisa",49 , 32945820934822));
	return (0);
}
*/
