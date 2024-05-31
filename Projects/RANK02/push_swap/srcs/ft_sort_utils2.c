/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:24:32 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 19:05:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_issorted(t_list *list)
{
	if (list == NULL)
		return (true);
	while (list->next != NULL)
	{
		if (ft_smaller(list->content, list->next->content, 0) == false)
			return (false);
		list = list->next;
	}
	return (true);
}

void	ft_optimize_moves_a(t_list **list_a, t_list **list_b, \
	t_rotate *rot, t_list *node)
{
	int		i;
	int		rotate[6];
	t_list	*tmp;

	i = 0;
	rotate[RR] = 0;
	rotate[RRR] = 0;
	rotate[RRB] = INT_MAX;
	ft_setmoves(rot, rotate, true);
	tmp = *list_a;
	while (ft_equal(tmp->content, node->content, 0) == false && i++ != -1)
		tmp = tmp->next;
	if (i > ft_lstsize(*list_a) / 2)
		rotate[RRA] = ft_lstsize(*list_a) - i;
	else
		rotate[RA] = i;
	i = 0;
	tmp = *list_b;
	while (ft_equal(tmp->content, node->content, 2) == false && i++ != -1)
		tmp = tmp->next;
	if (i > ft_lstsize(*list_b) / 2)
		rotate[RRB] = ft_lstsize(*list_b) - i;
	else
		rotate[RB] = i;
	return (ft_setmoves(rot, rotate, false));
}

void	ft_optimize_moves_b(t_list **list_a, t_list **list_b, \
	t_rotate *rot, t_list *node)
{
	int		i;
	int		rotate[6];
	t_list	*tmp;

	i = 0;
	rotate[RR] = 0;
	rotate[RRR] = 0;
	rotate[RRB] = INT_MAX;
	ft_setmoves(rot, rotate, true);
	tmp = *list_b;
	while (ft_equal(tmp->content, node->content, 0) == false && i++ != -1)
		tmp = tmp->next;
	if (i > ft_lstsize(*list_b) / 2)
		rotate[RRB] = ft_lstsize(*list_b) - i;
	else
		rotate[RB] = i;
	i = 0;
	tmp = *list_a;
	while (ft_equal(tmp->content, node->content, 2) == false && i++ != -1)
		tmp = tmp->next;
	if (i > ft_lstsize(*list_a) / 2)
		rotate[RRA] = ft_lstsize(*list_a) - i;
	else
		rotate[RA] = i;
	return (ft_setmoves(rot, rotate, false));
}

void	ft_optimize(t_list **list_a, t_list **list_b, \
	t_rotate *rot, bool pos)
{
	t_list	*temp;

	temp = *list_b;
	if (pos == false)
		temp = *list_a;
	rot->ops[RA] = 100;
	rot->ops[RB] = 100;
	rot->ops[RR] = 100;
	rot->ops[RRA] = 100;
	rot->ops[RRB] = 100;
	rot->ops[RRR] = 100;
	while (temp != NULL)
	{
		if (pos == false)
			ft_optimize_moves_a(list_a, list_b, rot, temp);
		else
			ft_optimize_moves_b(list_a, list_b, rot, temp);
		temp = temp->next;
	}
}
