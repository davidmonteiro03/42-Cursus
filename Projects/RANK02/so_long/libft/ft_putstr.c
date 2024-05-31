/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:27:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 17:46:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str, int *ret)
{
	if (str == NULL)
		*ret += write(STDOUT_FILENO, "(null)", 6);
	else
		while (*str != '\0')
			ft_putchar(*str++, ret);
}
