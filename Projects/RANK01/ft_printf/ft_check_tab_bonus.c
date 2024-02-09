/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:22:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:22:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_tab_bonus(char *frmt, size_t i, char *arg_str, t_list **arg)
{
	int		num;
	int		trunc;
	char	fill;

	if (frmt[ft_strlen(frmt) - 1] == '%')
		return ;
	fill = ' ';
	if (ft_strchr("0.-", frmt[i]))
		if (ft_strchr("0.", frmt[i++]))
			fill = frmt[i - 1];
	num = 0;
	while (frmt[i] && ft_isdigit(frmt[i]))
		num = num * 10 + frmt[i++] - '0';
	trunc = num;
	num -= (int)ft_strlen(arg_str);
	if (!*arg_str && frmt[ft_strlen(frmt) - 1] == 'c')
		num--;
	if (fill == ' ')
		while (num-- > 0)
			ft_addchar_bonus(fill, arg, ft_strchr(frmt, '-') == NULL);
	else if (ft_strchr("0.", fill) && \
		ft_strchr("diuxX", frmt[ft_strlen(frmt) - 1]))
		ft_checkdec_bonus(frmt, fill, arg, num);
	else if (fill == '.' && frmt[ft_strlen(frmt) - 1] == 's')
		ft_truncate_bonus(arg, trunc);
}
