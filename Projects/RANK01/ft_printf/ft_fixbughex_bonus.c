/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixbughex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:18:23 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:35:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fixbughex_bonus(t_list **arg, t_list *node1, t_list *node2)
{
	t_list	*new_node1;
	t_list	*new_node2;

	new_node1 = ft_lstnew(ft_datanew_bonus(ft_vtoc_bonus(node1->content)));
	new_node2 = ft_lstnew(ft_datanew_bonus(ft_vtoc_bonus(node2->content)));
	ft_removenode_bonus(arg, node1);
	ft_removenode_bonus(arg, node2);
	ft_lstadd_front(arg, new_node2);
	ft_lstadd_front(arg, new_node1);
}
