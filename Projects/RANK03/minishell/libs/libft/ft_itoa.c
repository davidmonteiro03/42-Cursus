/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:07:15 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		size;
	char	*str;

	neg = 1;
	if (n == 0)
		return (ft_strdup("0"));
	size = count(n);
	if (n < 0)
	{
		neg = -neg;
		size++;
	}
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size--] = 0;
	while (n != 0)
	{
		str[size--] = n % 10 * neg + 48 ;
		n /= 10;
	}
	if (size == 0)
		str[0] = '-';
	return (str);
}
