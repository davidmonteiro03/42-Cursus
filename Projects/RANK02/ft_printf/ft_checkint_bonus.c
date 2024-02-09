/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:20:56 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:34:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkint_bonus(t_list **arg)
{
	t_list	*tmp;

	if (ft_lstsize(*arg) < 3)
		return ;
	tmp = (*arg)->next;
	while (tmp)
	{
		if (ft_strchr("+-", ft_vtoc_bonus(tmp->content)))
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		ft_fixbugint_bonus(arg, tmp);
}
