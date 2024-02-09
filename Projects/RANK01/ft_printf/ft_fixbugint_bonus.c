/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixbugint_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:20:15 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:35:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fixbugint_bonus(t_list **arg, t_list *node)
{
	t_list	*new_node;

	new_node = ft_lstnew(ft_datanew_bonus(ft_vtoc_bonus(node->content)));
	ft_removenode_bonus(arg, node);
	ft_lstadd_front(arg, new_node);
}
