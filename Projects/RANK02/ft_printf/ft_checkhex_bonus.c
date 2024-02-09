/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkhex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:19:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:33:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkhex_bonus(t_list **arg)
{
	char	curr;
	char	next;
	t_list	*tmp;

	if (ft_lstsize(*arg) < 4)
		return ;
	tmp = (*arg)->next;
	while (tmp && tmp->next)
	{
		curr = ft_vtoc_bonus(tmp->content);
		next = ft_vtoc_bonus(tmp->next->content);
		if (curr == '0' && ft_tolower(next) == 'x')
			break ;
		tmp = tmp->next;
	}
	if (tmp->next)
		ft_fixbughex_bonus(arg, tmp, tmp->next);
}
