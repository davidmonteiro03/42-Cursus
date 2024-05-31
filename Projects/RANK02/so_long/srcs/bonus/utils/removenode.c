/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removenode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:19:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/05 22:44:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_removenode(t_list **list, t_list *node, void (*del)(void *))
{
	t_list	*tmp;

	if (!list || !*list || !node)
		return ;
	if (*list == node)
	{
		*list = node->next;
		if (del != NULL)
			del(node->content);
		free(node);
		return ;
	}
	tmp = *list;
	while (tmp->next && tmp->next != node)
		tmp = tmp->next;
	if (tmp->next)
	{
		tmp->next = node->next;
		if (del != NULL)
			del(node->content);
		free(node);
	}
}
