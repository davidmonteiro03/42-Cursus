/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:36:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 22:20:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_swap(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (true);
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
	return (true);
}

bool	ft_push(t_list **list_from, t_list **list_to)
{
	t_list	*tmp;

	if (list_from == NULL || *list_from == NULL)
		return (true);
	tmp = *list_from;
	*list_from = (*list_from)->next;
	tmp->next = *list_to;
	*list_to = tmp;
	return (true);
}

bool	ft_rotate(t_list **list, int mode)
{
	t_list	*tmp;
	t_list	*last;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (true);
	if (mode == 0)
	{
		tmp = *list;
		*list = (*list)->next;
		last = ft_lstlast(*list);
		last->next = tmp;
		tmp->next = NULL;
		return (true);
	}
	tmp = *list;
	last = ft_lstlast(*list);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *list;
	*list = last;
	return (true);
}
