/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:06:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:06:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addnbr_bonus(int num, t_list **list)
{
	if (num == -2147483648)
	{
		ft_addstr_bonus("-2147483648", list);
		return ;
	}
	if (num < 0)
	{
		ft_addchar_bonus('-', list, false);
		num = -num;
	}
	if (num > 9)
	{
		ft_addnbr_bonus(num / 10, list);
		ft_addnbr_bonus(num % 10, list);
	}
	else
		ft_addchar_bonus(num + '0', list, false);
}
