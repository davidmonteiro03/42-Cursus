/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:10:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:10:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_bonus(char *frmt, size_t *i, \
	char *arg_str, t_list **arg)
{
	if (frmt[*i] == '#' && ft_strchr("xX", frmt[ft_strlen(frmt) - 1]) && \
		arg_str[0] != '0')
	{
		ft_addchar_bonus(frmt[ft_strlen(frmt) - 1], arg, true);
		ft_addchar_bonus('0', arg, true);
	}
	else if (ft_strchr("+ ", frmt[*i]) && \
		ft_strchr("di", frmt[ft_strlen(frmt) - 1]) && ft_atoi(arg_str) >= 0)
		ft_addchar_bonus(frmt[*i], arg, true);
	(*i)++;
}
