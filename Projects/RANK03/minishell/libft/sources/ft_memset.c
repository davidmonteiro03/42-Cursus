/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:42:34 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/26 02:12:21 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_memset --- Fills the 'n' bytes with constant 'i'
**
**SYNOPSIS: void	*ft_memset(void *ptr, int i, size_t n)
**
**DESCRIPTION: Fills the first n bytes of memory area pointed to by ptr with
**	the constant byte (unsigned char) i.
**
**PARAMETERS:	ptr: pointer to a memory area
**		n : number of bytes that would be target
**		i: constant value to be written in 'n' bytes
**
**RETURN VALUE: return a the pointer of the memory area.
**
**ERRORS: \NA
**
**FUNCTION: \NA */
void	*ft_memset(void *ptr, int i, size_t n)
{
	while (n > 0)
		((unsigned char *)ptr)[--n] = (unsigned char)i;
	return (ptr);
}
/*
int	main(void)
{
	char	a[5] = "coisa";
	char	*ptr;
	int		i;
	int		k;

	k = -1;
	i = 5;
	ptr = a;
	ft_memset(ptr, '\t', 2);
	while (++k < i)
	{
		if (ptr[k])
		{
			write(1, &ptr[k], 1);
			write(1, "$\n", 2);
			continue ;
		}
		write(1, "(null)\n", 7);
	}
}
*/
