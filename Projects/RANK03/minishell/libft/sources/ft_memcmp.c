/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <preis-ne@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:47:30 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/03 12:24:59 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_memcmp -- compare memory areas
**
**SYNOPSIS: int	ft_memcmp(const void *s1, const void *s2, size_t n);
**
**DESCRIPTION: The ft_memcmp() function compares the FIRST 'n' bytes (each 
**	interpreted as unsigned char) of the memory areas 's1' and 's2'.
**
**PARAMETERS:	s1: first string to compare
**		s2: second string to compare;
**		n : number of memory bytes to compare from s1.
**
**RETURN VALUE: Returns an integer less than, equal to, or greater than zero
**	if the first 'n' bytes of s1 is found, respectively, to be
**	less than, to match, or be greater than the first 'n' bytes of 's2'.
**	For a nonzero return value, the sign is determined by the sign of 
**	the difference between the first pair of bytes (interpreted as 
**	unsigned char) that differ in 's1' and 's2'.
**	If 'n' is zero, returns zero.
**
**ERRORS: \NA
**
**FUNTION: \NA */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d", ft_memcmp(argv[1], argv[2], argv[3][0]));
	}
}
*/
