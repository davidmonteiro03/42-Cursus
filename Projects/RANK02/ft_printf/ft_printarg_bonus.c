/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:04:27 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:04:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printarg_bonus(t_list *arg, int *ret)
{
	t_list	*tmp;

	tmp = arg;
	while (tmp)
	{
		ft_printdata_bonus(tmp->content, ret);
		tmp = tmp->next;
	}
}
