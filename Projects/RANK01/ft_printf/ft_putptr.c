/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:55:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 10:14:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(const void *ptr, int *ret)
{
	if (ptr != NULL)
	{
		printf("%p", ptr);
		fflush(stdout);
	}
	else
		*ret += write(1, "(nil)", 5);
}
