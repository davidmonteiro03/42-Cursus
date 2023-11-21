/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:14:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/05 15:54:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;

	if (!dest && !src)
		return (NULL);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	i = -1;
	while (++i < n)
		aux_dest[i] = aux_src[i];
	return (dest);
}
