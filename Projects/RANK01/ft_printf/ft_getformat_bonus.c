/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getformat_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:49:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:01:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getformat_bonus(const char *format, int *i)
{
	int		start;
	int		end;

	start = ++(*i);
	while (format[*i] && !ft_strchr("cspdiuxX%%", format[*i]))
		(*i)++;
	end = *i + 1;
	return (ft_substr(format, start, end - start));
}
