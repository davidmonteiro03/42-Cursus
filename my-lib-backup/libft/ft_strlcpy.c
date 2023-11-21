/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:52:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/05 15:43:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		i = 0;
		while (src[i])
			i++;
		return (i);
	}
	i = -1;
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	if (i < size)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
