/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:48:11 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/29 00:16:20 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_bzero --- Write NULLS (erase memory) in 'n' byter of memory
**
**SYNOPSIS: void	ft_bzero(void *ptr, size_t n)
**
**DESCRIPTION: The ft_bzero() function erases the data in the n bytes of the 
**	memory starting at the location pointed by ptr, by writing zeros (bytes 
**	containing '\0') to that area.
**
**PARAMETERS:	ptr: pointer of starting memory
**		n : bytes of memory
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: \NA */
void	ft_bzero(void *ptr, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)ptr)[--n] = '\0';
	}
}
/*
int	main(void)
{
	char	a[] = "coisa";
	char	*ptr;
	char	*str;
	int	i = 5;

	ptr = a;
	ft_bzero(ptr,2);
	while (i-- > 0)
	{
		write(1, ptr++ , 1);
	}
}
*/
