/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:10:23 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/04 06:34:08 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strlcpy --- size-bounded string copying and concatenation
**
**SYNOPSIS: size_t	ft_strlcpy(char *dest, const char *src, size_t n);
**
**DESCRIPTION: The ft_strlcpy() function copy strings, taking the full size 
**	of the buffer (not just the length) and guarantee to NUL-terminate
**	the result),(as long as n is langer than 0). ft_strlcpy() only operate
**	on true "C" strings meanning that src must be a NUL-terminated.
**	The ft_strlcpy function copies up to n-1 characters from the NUL-
**	-terminated string src to dest, NUL-terminating the result.
**
**PARAMETERS:	dest: string copied.
**		src: string to be copied;
**		n: number of bytes to be copied;
**
**RETURN VALUES: returns the total length of the string tried to create,
**	i.e. src length.
**
**ERRORS: \NA
**
**FUNCTION: \NA */
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (!src || !dest || !n)
		return (len);
	while ((--n) && *src)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	*dest++ = '\0';
	return (len);
}
/*
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (((n - 1) > i) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
*/
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "coisa";
	char	dest[] = "destino";

	printf("%zu\n", ft_strlcpy(dest,src,5));
	printf("%s\n", dest);

	char	src1[] = "pois";
	char	dest1[] = "destino";
	
	printf("%zu\n", ft_strlcpy(dest1, src1, 6));
	printf("%s\n", dest1);
}
*/
