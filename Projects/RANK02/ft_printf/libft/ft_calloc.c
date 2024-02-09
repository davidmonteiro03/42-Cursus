/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:08:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/03 16:28:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb && size && nmemb > (UINT_MAX / size))
		return (NULL);
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
