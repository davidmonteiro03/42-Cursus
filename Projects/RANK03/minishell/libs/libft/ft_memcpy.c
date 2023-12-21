/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:53:52 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest,
						void const *src,
						size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!src && !dest)
		return ((void *)0);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
