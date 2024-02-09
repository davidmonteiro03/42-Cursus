/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:23:26 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:23:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_bonus(const char *format, int *i, int *ret, va_list args)
{
	t_list	*arg;
	char	*frmt;

	frmt = ft_getformat_bonus(format, i);
	arg = NULL;
	ft_format_bonus(frmt[ft_strlen(frmt) - 1], &arg, args);
	ft_addflags_bonus(frmt, &arg);
	return (ft_printarg_bonus(arg, ret), free(frmt), ft_lstclear(&arg, &free));
}
