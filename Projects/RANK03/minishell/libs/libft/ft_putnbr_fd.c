/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:30:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	neg;

	if (fd < 0)
		return ;
	neg = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		neg *= -1;
	}
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10 * neg, fd);
	ft_putchar_fd(n % 10 * neg + 48, fd);
}
