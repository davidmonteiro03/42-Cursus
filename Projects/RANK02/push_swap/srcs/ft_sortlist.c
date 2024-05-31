/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:48:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 22:31:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort3(t_list **list_a)
{
	t_list	*min;
	t_list	*max;

	if (ft_issorted(*list_a) == true)
		return ;
	min = ft_gettarget(*list_a, &ft_smaller);
	max = ft_gettarget(*list_a, &ft_greater);
	if (*list_a == min)
		return (ft_execute("rra", list_a, NULL, true), \
				ft_execute("sa", list_a, NULL, true), (void)0);
	if (*list_a == max)
	{
		ft_execute("ra", list_a, NULL, true);
		if (ft_smaller((*list_a)->content, (*list_a)->next->content, \
			false) == false)
			ft_execute("sa", list_a, NULL, true);
		return ;
	}
	if (max == ft_lstlast(*list_a))
		return (ft_execute("sa", list_a, NULL, true), (void)0);
	return (ft_execute("rra", list_a, NULL, true), (void)0);
}

void	ft_sort4_5(t_list **list_a, t_list **list_b)
{
	t_list	*min;
	t_list	*sec_min;

	if (ft_issorted(*list_a) == true)
		return ;
	min = ft_gettarget(*list_a, &ft_smaller);
	sec_min = ft_findsecmin(*list_a);
	while (ft_lstsize(*list_a) > 3)
	{
		while (*list_a != min && *list_a != sec_min)
			ft_execute("ra", list_a, list_b, true);
		ft_execute("pb", list_a, list_b, true);
	}
	ft_sort3(list_a);
	if (*list_b != NULL && (*list_b)->next != NULL && \
		ft_smaller((*list_b)->content, (*list_b)->next->content, 0) == true)
		ft_execute("sb", list_a, list_b, true);
	while (ft_lstsize(*list_b) > 0)
		ft_execute("pa", list_a, list_b, true);
	if (ft_greater((*list_a)->content, (*list_a)->next->content, 0) == true)
		ft_execute("sa", list_a, list_b, true);
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	t_rotate	rot;

	rot = (t_rotate){0};
	ft_push_best_to_b(list_a, list_b, &rot);
	ft_sort3(list_a);
	ft_push_best_to_a(list_a, list_b, &rot);
	while (ft_issorted(*list_a) == false)
		ft_execute("rra", list_a, list_b, true);
}

void	ft_sortlist(t_list **list_a, t_list **list_b)
{
	if (ft_issorted(*list_a) == true)
		return ;
	if (ft_lstsize(*list_a) == 2)
		return (ft_execute("sa", list_a, NULL, true), (void)0);
	if (ft_lstsize(*list_a) == 3)
		return (ft_sort3(list_a));
	if (ft_lstsize(*list_a) >= 4 && ft_lstsize(*list_a) <= 5)
		return (ft_sort4_5(list_a, list_b));
	ft_sort(list_a, list_b);
}
