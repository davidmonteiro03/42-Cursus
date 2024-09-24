/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:16:37 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/29 00:25:35 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_memmove --- Copies 'n' bytes from 'src' to 'dest' though a 'tmp' 
**	pointer
**
**SYNOPSIS: void	*ft_memmove(void *dest, const void *src, size_t n)
**
**DESCRIPTION: The ft_memmove() function copies n bytes from memory area src
**	to memory area dest. The memory may overlap: copying takes place as
**	though the bytes in src are first copied into a array that
**	does not overlap src or dest, and the bytes are then copied from
**	the temporary array to dest.
**
**PARAMETERS:	dest: pointer with a copy of 'src'
**		src: pointer to be moved to 'tmp'
**		tmp: intermediate pointer with a 'dest' copy to preserve 'dest'
**
**RETURN VALUE: Returns a pointer to dest.
**
**ERRORS: Condition to nulls pointer and 'src' may overlap  'dest'
**
**FUNTION: \NA */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;
	size_t	i;

	tmp = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	i = -1;
	if (dest > src)
		ft_memcpy(dest, tmp, n);
	else
		while (++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)tmp)[i];
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src;
	char	*dest;	
	char	a[] = "coisalinda";
	char	b[] = "destino";

	src = a;
	dest = b;
	printf("%s\n", (char *)ft_memmove(dest, src, 7));
	printf("%s\n", (char *)ft_memmove(dest, src, 2));
	printf("%s\n", (char *)memmove(dest, src, 2));
}
*/
