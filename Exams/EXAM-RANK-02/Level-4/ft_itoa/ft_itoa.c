/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:03:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 09:40:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_len(int nbr)
{
	size_t	result;

	if (nbr == 0)
		return (1);
	result = 0;
	while (nbr != 0)
	{
		result++;
		nbr /= 10;
	}
	return (result);
}

char	*ft_array(size_t len, long int tmp)
{
	char	*result;

	if (tmp < 0)
	{
		len++;
		tmp = -tmp;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (tmp == 0)
	{
		*result = '0';
		return (result);
	}
	while (tmp > 0)
	{
		result[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (result[0] == '\0')
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int nbr)
{
	long int	tmp;
	char		*result;

	tmp = (long int)nbr;
	result = ft_array(ft_len(nbr), tmp);
	if (result == NULL)
		return (NULL);
	return (result);
}
