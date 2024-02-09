/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:07:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:07:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addnbr_base_bonus(unsigned int num, \
	unsigned int base, t_list **list, char c)
{
	char	*base_str;

	if (c == ft_tolower(c))
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (num > base - 1)
	{
		ft_addnbr_base_bonus(num / base, base, list, c);
		ft_addnbr_base_bonus(num % base, base, list, c);
	}
	else
		ft_addchar_bonus(base_str[num % base], list, false);
}
