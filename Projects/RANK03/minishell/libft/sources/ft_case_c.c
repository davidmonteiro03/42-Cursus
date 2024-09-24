/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:00:31 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:31:33 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_case_c(const char *str, va_list args, int *i, int *len)
{
	int	width;
	int	justify;

	justify = ft_minus(str, i);
	width = ft_width(str, i);
	if (justify == 0)
		while ((width)-- > 1)
			ft_putchar_len(' ', len);
	ft_putchar_len(va_arg(args, int), len);
	if (justify == 1)
		while ((width)-- > 1)
			ft_putchar_len(' ', len);
	while (str[*i] != 'c')
		(*i)++;
}
