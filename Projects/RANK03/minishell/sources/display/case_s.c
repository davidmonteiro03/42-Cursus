/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:01:33 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_print_nulls(const char *str, t_tmp *tmp)
{
	int		cutsize;
	int		printsize;
	int		justify;
	int		strsize;

	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	justify = display_minus(str, tmp);
	strsize = 0;
	if ((cutsize >= 0 && cutsize <= 5) || cutsize == -1)
		display_putstr_lenspaces(tmp, &strsize, &printsize);
	else
	{
		printsize -= 6;
		if (justify == 1)
		{
			display_putstr_lennull(tmp);
			display_putstr_lenspaces(tmp, &strsize, &printsize);
		}
		else if (justify == 0)
		{
			display_putstr_lenspaces(tmp, &strsize, &printsize);
			display_putstr_lennull(tmp);
		}
	}
}

static void	ft_print( const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;
	int		strsize;
	int		cutsize;
	int		printsize;
	int		justify;

	va_copy(dst, args);
	strsize = ft_strlen(va_arg(dst, char *));
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	justify = display_minus(str, tmp);
	if (cutsize == -1)
		strsize = 0;
	else if (cutsize >= 0 && strsize > cutsize)
		strsize = cutsize;
	if (justify == 0)
		display_putstr_lenspaces(tmp, &strsize, &printsize);
	else if (justify == 1)
		display_putstr_len(va_arg(args, char *), tmp, &strsize);
	if (justify == 0)
		display_putstr_len(va_arg(args, char *), tmp, &strsize);
	else if (justify == 1)
		display_putstr_lenspaces(tmp, &strsize, &printsize);
	va_end(dst);
}

void	display_case_s(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;

	va_copy(dst, args);
	if (va_arg(dst, char *))
		ft_print(str, args, tmp);
	else
		ft_print_nulls(str, tmp);
	while (str[tmp->i] != 's')
		(tmp->i)++;
	va_end(dst);
}
