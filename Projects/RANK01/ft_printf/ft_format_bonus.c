/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:08:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:08:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_bonus(char c, t_list **list, va_list args)
{
	void	*ptr;

	if (c == 'c')
		return (ft_addchar_bonus(va_arg(args, int), list, false));
	if (c == 's')
		return (ft_addstr_bonus(va_arg(args, char *), list));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_addstr_bonus("(nil)", list));
		return (ft_addptr_bonus(ptr, list));
	}
	if (c == 'd' || c == 'i')
		return (ft_addnbr_bonus(va_arg(args, int), list));
	if (c == 'u')
		return (ft_addnbr_base_bonus(va_arg(args, unsigned int), 10, list, c));
	if (ft_tolower(c) == 'x')
		return (ft_addnbr_base_bonus(va_arg(args, unsigned int), 16, list, c));
	if (c == '%')
		return (ft_addchar_bonus('%', list, false));
}
