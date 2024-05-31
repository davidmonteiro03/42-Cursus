/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:08:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 09:01:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_display_content(void *content)
{
	t_element	*tmp;

	tmp = (t_element *)content;
	ft_putstr_fd(" => ", 1);
	ft_putnbr_fd(tmp->number, 1);
	ft_putstr_fd(" -> ", 1);
	ft_putnbr_fd(tmp->target, 1);
}

void	ft_display(t_list *list)
{
	while (list)
	{
		ft_display_content(list->content);
		ft_putendl_fd("", 1);
		list = list->next;
	}
}
