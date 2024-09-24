/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <preis-ne@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:30:25 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/02 08:19:43 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_calloc --- allocate clear memory
**
**SYNOPSIS: void	*calloc(size_t n , size_t size);
**
**DESCRIPTION: The calloc() function allocates memory for an ARRAY of 'n' 
**	elements of 'size' bytes each returns a pointer to the allocated memory.
**	The memory is set to ZERO. If 'n' or 'size' is 0, then calloc returns 
**	either 	NULL, or a unique pointer value that can later be successfully 
**	passed to free(). If the multiplication if 'n' and 'size' would result 
**	in integer overflow, then calloc() returns an error. By contrast, an
**	integer overflow would not be detected in the following call to
**	malloc(), with the result that an incorrectly sized block of memory 
**	would be allocated: malloc(n * size);
**
**PARAMETERS:	n: number of elements of the array pointed
**		size:
**
**RETURN VALUE:	return a pointer to the allocated memory for any type.
**	
**
**ERRORS: On error return NULL;
**	NULL may also be returned by a successful call to malloc() with
**	'size' zero or by a successful call to calloc() with 'n' and size
**	equal to zero.
**
**FUNCTIONS: malloc()*/
void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, n * size);
	return (ptr);
}
/*
int	main(void)
{
	char	*ptr;
	int	i;
	
	ptr = ft_calloc(5,1);
	i = 0;
	while (ptr[i])
		write(1, &ptr[i++], 1);
	return(0);

}
*/
