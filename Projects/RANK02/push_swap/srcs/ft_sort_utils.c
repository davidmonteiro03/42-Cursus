/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:40:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 19:17:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_gettarget(t_list *list, bool (*compare)(void *, void *, int))
{
	t_list	*target;

	if (list == NULL)
		return (NULL);
	target = list;
	while (list != NULL)
	{
		if (compare(list->content, target->content, 0) == true)
			target = list;
		list = list->next;
	}
	return (target);
}

void	ft_set_targets_b(t_list **list_a, t_list **list_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*max_b_node;

	max_b_node = ft_gettarget(*list_b, &ft_greater);
	temp_a = *list_a;
	while (temp_a != NULL)
	{
		temp_b = *list_b;
		((t_element *)(temp_a->content))->target = INT_MIN;
		while (temp_b != NULL)
		{
			if (ft_smaller(temp_b->content, temp_a->content, 0) == true && \
				ft_greater(temp_b->content, temp_a->content, 2) == true)
				((t_element *)(temp_a->content))->target = \
				((t_element *)(temp_b->content))->number;
			temp_b = temp_b->next;
		}
		if (((t_element *)(temp_a->content))->target == INT_MIN)
			((t_element *)(temp_a->content))->target = \
			((t_element *)(max_b_node->content))->number;
		temp_a = temp_a->next;
	}
}

void	ft_set_targets_a(t_list **list_a, t_list **list_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*min_a_node;

	min_a_node = ft_gettarget(*list_a, &ft_smaller);
	temp_b = *list_b;
	while (temp_b != NULL)
	{
		temp_a = *list_a;
		((t_element *)(temp_b->content))->target = INT_MAX;
		while (temp_a != NULL)
		{
			if (ft_greater(temp_a->content, temp_b->content, 0) == true && \
				ft_smaller(temp_a->content, temp_b->content, 2) == true)
				((t_element *)(temp_b->content))->target = \
				((t_element *)(temp_a->content))->number;
			temp_a = temp_a->next;
		}
		if (((t_element *)(temp_b->content))->target == INT_MAX)
			((t_element *)(temp_b->content))->target = \
			((t_element *)(min_a_node->content))->number;
		temp_b = temp_b->next;
	}
}

void	ft_push_best_to_b(t_list **list_a, t_list **list_b, t_rotate *rot)
{
	ft_execute("pb", list_a, list_b, true);
	ft_execute("pb", list_a, list_b, true);
	while (ft_lstsize(*list_a) > 3)
	{
		ft_set_targets_b(list_a, list_b);
		ft_optimize(list_a, list_b, rot, false);
		ft_multiexecute(list_a, list_b, rot);
		ft_execute("pb", list_a, list_b, true);
	}
}

void	ft_push_best_to_a(t_list **list_a, t_list **list_b, t_rotate *rot)
{
	while (ft_lstsize(*list_b) > 0)
	{
		ft_set_targets_a(list_a, list_b);
		ft_optimize(list_a, list_b, rot, true);
		ft_multiexecute(list_a, list_b, rot);
		ft_execute("pa", list_a, list_b, true);
	}
}
