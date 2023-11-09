/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:33:37 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/06 19:35:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(size_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len + 2);
}

int	ft_putptr(void *ptr)
{
	size_t	mem;
	size_t	size;
	size_t	aux;
	int		num;
	char	*str;

	mem = (size_t)ptr;
	aux = mem;
	size = ft_len(mem);
	str = ft_converthex(aux, size);
	if (!str)
		return (0);
	num = ft_putstr(str);
	free(str);
	return (num);
}
