/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addflags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:23:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:23:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addflags_bonus(char *frmt, t_list **arg)
{
	char	*arg_str;
	size_t	i;

	i = 0;
	arg_str = ft_ltoa_bonus(*arg);
	if (ft_strchr("# +", frmt[i]))
		ft_check_flag_bonus(frmt, &i, arg_str, arg);
	free(arg_str);
	arg_str = ft_ltoa_bonus(*arg);
	ft_check_tab_bonus(frmt, i, arg_str, arg);
	ft_findbug_bonus(arg, frmt[ft_strlen(frmt) - 1]);
	return (free(arg_str));
}
