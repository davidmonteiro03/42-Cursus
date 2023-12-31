/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:31:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 16:08:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_get_angle(t_cub *cub, char c)
{
	int	angle;

	angle = -1;
	if (c == 'N')
		angle = 270;
	else if (c == 'S')
		angle = 90;
	else if (c == 'E')
		angle = 0;
	else
		angle = 180;
	return ((void)cub, angle);
}

unsigned long	ft_min(unsigned long a, unsigned long b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned long	ft_max(unsigned long a, unsigned long b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned long	cub_contrast_color(unsigned long color, \
	unsigned long dark, unsigned long light)
{
	auto unsigned long r = (color >> 16) & 0xFF;
	auto unsigned long g = (color >> 8) & 0xFF;
	auto unsigned long b = color & 0xFF;
	auto unsigned long contrast = ((r * 299) + (g * 587) + (b * 114)) / 1000;
	if (contrast > 128)
		return (dark);
	return (light);
}

long int	cub_atol(const char *nptr)
{
	long int	num;
	long int	sign;
	size_t		i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	return (num * sign);
}
