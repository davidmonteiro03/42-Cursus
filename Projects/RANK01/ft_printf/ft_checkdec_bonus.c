/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdec_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:22:07 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:22:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkdec_bonus(char *frmt, char fill, t_list **arg, int num)
{
	char	*tmp1;
	int		tmp2;

	tmp1 = ft_ltoa_bonus(*arg);
	tmp2 = ft_atoi(tmp1);
	while (num-- > 0)
		ft_addchar_bonus('0', arg, ft_strchr(frmt, '-') == NULL);
	if (ft_strchr("di", frmt[ft_strlen(frmt) - 1]) && fill == '.')
		if (ft_strlen(tmp1) <= 10 && tmp2 < 0 && num == -1)
			ft_addchar_bonus('0', arg, ft_strchr(frmt, '-') == NULL);
	free(tmp1);
}
