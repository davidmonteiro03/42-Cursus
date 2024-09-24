/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:56:21 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 05:34:14 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_putnbr_fd --- write an integer on a file descritptor
**
**SYNOPSIS: void ft_putnbr_fd(int n, int fd);
**
**DESCRIPTION: Outputs the integer ’n’ to the given file descriptor.
**
**PARAMETERS:	n: The integer to output.
**		fd: The file descriptor on chich to write.
**
**RETURN VALUE: \NA
**
**ERRORS: 'fd' value can't take negative numbers
**
**FUNCTION: write */
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}
*/
