/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:35:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/03 14:40:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*aux_s1;
	const unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (aux_s1[i] != aux_s2[i])
			return (aux_s1[i] - aux_s2[i]);
	return (0);
}
