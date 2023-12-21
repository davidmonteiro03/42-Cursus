/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:43:44 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:45:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	res;
	long long int	neg;

	res = 0;
	neg = 1;
	while (*nptr == '\t' || *nptr == ' ' || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			neg = -neg;
	}
	while (ft_isdigit(*nptr))
	{
		if (res > FT_INT_MAX)
			return (FT_INT_MAX_PLUS);
		if (res < FT_INT_MIN)
			return (FT_INT_MIN_PLUS);
		res = res * 10 + *(nptr++) - '0';
	}
	return (res * neg);
}
