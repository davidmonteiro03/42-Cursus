/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 05:22:00 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_print_nil(const char *str, t_tmp *tmp)
{
	int	justify;
	int	printsize;
	int	strsize;

	strsize = 5;
	justify = display_minus(str, tmp);
	printsize = display_width(str, tmp);
	if (justify == 1)
	{
		display_putstr_lennil(tmp);
		display_putstr_lenspaces(tmp, &strsize, &printsize);
	}
	else if (justify == 0)
	{
		display_putstr_lenspaces(tmp, &strsize, &printsize);
		display_putstr_lennil(tmp);
	}
}

static void	ft_print(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;
	int		justify;
	int		printsize;
	int		strsize;

	va_copy(dst, args);
	strsize = display_nbrlen(va_arg(dst, unsigned long long int), 16) + 2;
	justify = display_minus(str, tmp);
	printsize = display_width(str, tmp);
	if (justify == 1)
	{
		display_puthex_pre(str, tmp, -1);
		display_putnbr_base(va_arg(args, size_t), tmp, "0123456789abcdef");
		display_putstr_lenspaces(tmp, &strsize, &printsize);
	}
	else if (justify == 0)
	{
		display_putstr_lenspaces(tmp, &strsize, &printsize);
		display_puthex_pre(str, tmp, -1);
		display_putnbr_base(va_arg(args, size_t), tmp, "0123456789abcdef");
	}
	va_end(dst);
}

void	display_case_p(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;

	va_copy(dst, args);
	if (va_arg(dst, size_t))
		ft_print(str, args, tmp);
	else
		ft_print_nil(str, tmp);
	while (str[tmp->i] != 'p')
		(tmp->i)++;
	va_end(dst);
}
