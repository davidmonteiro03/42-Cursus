/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removenode_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:10:38 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:36:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_removenode_bonus(t_list **arg, t_list *node)
{
	t_list	*current;

	if (!node || !arg || !*arg)
		return ;
	if (*arg == node)
	{
		*arg = node->next;
		return (free(node->content), free(node));
	}
	current = *arg;
	while (current->next && current->next != node)
		current = current->next;
	if (!current->next)
		return ;
	current->next = node->next;
	return (free(node->content), free(node));
}
