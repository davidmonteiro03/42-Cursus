/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:18:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 19:23:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	int	bit;

	i = 8;
	while (i-- > 0)
	{
		bit = (octet >> i) & 1;
		if (bit == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}
