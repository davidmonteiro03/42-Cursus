/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:27:38 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/01 04:50:54 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_memcpy --- Copies 'n' bytes from 'src' to 'dest'
**
**SYNOPSIS: void	*ft_memcpy(void *dest, const void *src, size_t n);
**
**DESCRIPTION : The ft_memcpy() function copies n bytes from memory area src 
**	to memory area dest. The memory areas must not overlap.
**
**PARAMETERS:	n: bytes of memory
**		src: pointer to be copy
**		dest: pointer copied from 'src'
**
**RETURN VALUE: Returns a pointer to 'dest'.
**
**ERRORS: The mempry areas must not overlap.
**
**FUNTION: \NA */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (0);
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src;
	char	*dest;
	char	a[] = "coisa";
	char	b[] = "poi";
	int	i;

	src = a;
	dest = b;
	i = 0;
	printf("%s\n", (char*)ft_memcpy(dest,src,4 ));
	printf("%s", (char*)memcpy(dest,src,4));	
}
*/
