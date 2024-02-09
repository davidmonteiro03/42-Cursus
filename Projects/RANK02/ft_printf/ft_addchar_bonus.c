/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:05:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:54:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addchar_bonus(char c, t_list **list, bool pos)
{
	if (!pos)
		ft_lstadd_back(list, ft_lstnew(ft_datanew_bonus(c)));
	else
		ft_lstadd_front(list, ft_lstnew(ft_datanew_bonus(c)));
}
