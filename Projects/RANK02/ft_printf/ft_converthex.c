/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:53:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:53:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_converthex(size_t num, size_t size)
{
	char	*base;
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	base = "0123456789abcdef";
	while (num > 0 && size > 1)
	{
		str[size--] = base[num % 16];
		num /= 16;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}
