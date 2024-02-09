/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:05:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:06:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addstr_bonus(char *str, t_list **list)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_addchar_bonus(*str++, list, false);
}
