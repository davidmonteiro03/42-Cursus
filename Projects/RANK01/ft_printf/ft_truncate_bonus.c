/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:21:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:21:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_truncate_bonus(t_list **arg, int trunc)
{
	t_list	*tmp;
	t_list	*save;

	tmp = *arg;
	if (trunc >= ft_lstsize(*arg))
		return ;
	while (trunc-- > 0)
		tmp = tmp->next;
	while (tmp)
	{
		save = tmp->next;
		ft_removenode_bonus(arg, tmp);
		tmp = save;
	}
}
