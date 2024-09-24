/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:15:00 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/29 08:10:29 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strlcat --- size-bounded string copying and concatenation
**
**SYNOPSIS: size_t	ft_strlcat(char *dest, const char *src, size_t n);
**
**DESCRIPTION: The ft_strlcat() function concatenate string, taking the full
**	size of the buffer (not just the length) and guarantee to NUL-terminate
**	the result (as long as n is larger than 0 or as long as there is at
**	least one byte free is dest). Note that a byte for the NUL should be
**	included in 'n'. ft_strlcat() only operate on true "C" strings, meaning that
**	both 'src' and 'dest' must be Nul-terminated.
**	The ft_strlcat() function appends the NUL-terminated string 'src' to the
**	end of 'dest'. It will append at most n-ft_strlen(dest)-1 bytes, NUL-
**	-terminating the result.
**
**PARAMETERS:	dest: pointer of memory to be concatenate 'src';
**		src: string to be concatenate to 'dest'
**		n: number of bytes from 'src' to be concatenate.
**
**RETURN VALUE: Returns the initial lenght of 'dest' plus the length of 'src'.
**
**ERRORS:	If the function traverses 'n' without finding a NULL the length
**		of 'dest' is considered 'n' and returns 'n' plus 'src'
**		without add a nul-terminated.
**
**FUNCTION: \NA */
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;

	i = -1;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest >= n)
		return (n + len_src);
	while ((n - len_dest - 1) > ++i && src[i])
		dest[len_dest + i] = src[i];
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	*src = "origem";
	char	dest[20] = "ola";

	printf("%zu\n", ft_strlcat(dest, src, 2));
	printf("%s\n", dest);

	char	*src1 = "origem";
 	char	dest1[20] = "";	

	printf("%zu\n", ft_strlcat(dest1, src1, 7));
	printf("%s\n", dest1);
}
*/
