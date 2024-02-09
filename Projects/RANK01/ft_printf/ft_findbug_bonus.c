/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findbug_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:21:18 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:21:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findbug_bonus(t_list **arg, char c)
{
	if (ft_tolower(c) == 'x')
		ft_checkhex_bonus(arg);
	if (ft_strchr("di", c))
		ft_checkint_bonus(arg);
}
