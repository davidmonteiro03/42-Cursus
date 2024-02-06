/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:52:32 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:52:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, int *len)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-', len);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, len);
		ft_putnbr(num % 10, len);
	}
	else
		ft_putchar(num + '0', len);
}
