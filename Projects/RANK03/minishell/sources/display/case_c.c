/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:00:31 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_case_c(const char *str, va_list args, t_tmp *tmp)
{
	int	width;
	int	justify;

	justify = display_minus(str, tmp);
	width = display_width(str, tmp);
	if (justify == 0)
		while ((width)-- > 1)
			display_putchar_len(' ', tmp);
	display_putchar_len(va_arg(args, int), tmp);
	if (justify == 1)
		while ((width)-- > 1)
			display_putchar_len(' ', tmp);
	while (str[tmp->i] != 'c')
		(tmp->i)++;
}
