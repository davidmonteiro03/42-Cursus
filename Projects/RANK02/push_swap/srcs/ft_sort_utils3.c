/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:02:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 20:23:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_setmoves_ultimate(t_rotate *rot, int *rotate)
{
	if (rotate[RRA] > 0 && rotate[RRB] > 0)
	{
		while (rotate[RRA] && rotate[RRB])
		{
			rotate[RRR]++;
			rotate[RRA]--;
			rotate[RRB]--;
		}
	}
	if (rotate[RA] + rotate[RB] + rotate[RRA] + rotate[RRB] + rotate[RR] \
		+ rotate[RRR] < rot->ops[RA] + rot->ops[RB] + rot->ops[RRA] \
		+ rot->ops[RRB] + rot->ops[RRR] + rot->ops[RR])
	{
		rot->ops[RA] = rotate[RA];
		rot->ops[RB] = rotate[RB];
		rot->ops[RR] = rotate[RR];
		rot->ops[RRA] = rotate[RRA];
		rot->ops[RRB] = rotate[RRB];
		rot->ops[RRR] = rotate[RRR];
	}
}

void	ft_setmoves(t_rotate *rot, int *rotate, bool fill)
{
	if (fill == true)
	{
		rotate[RA] = INT_MAX;
		rotate[RB] = INT_MAX;
		rotate[RRA] = INT_MAX;
		return ;
	}
	if (rotate[RA] == INT_MAX)
		rotate[RA] = 0;
	if (rotate[RRA] == INT_MAX)
		rotate[RRA] = 0;
	if (rotate[RB] == INT_MAX)
		rotate[RB] = 0;
	if (rotate[RRB] == INT_MAX)
		rotate[RRB] = 0;
	if (rotate[RA] > 0 && rotate[RB] > 0)
	{
		while (rotate[RA] && rotate[RB])
		{
			rotate[RR]++;
			rotate[RA]--;
			rotate[RB]--;
		}
	}
	ft_setmoves_ultimate(rot, rotate);
}

t_list	*ft_findsecmin(t_list *list)
{
	t_list	*min;
	t_list	*target;

	if (list == NULL)
		return (NULL);
	min = ft_gettarget(list, &ft_smaller);
	target = NULL;
	while (list != NULL)
	{
		if (ft_equal(list->content, min->content, 0) == true)
		{
			list = list->next;
			continue ;
		}
		if (target == NULL)
			target = list;
		if (ft_smaller(list->content, target->content, 0) == true)
			target = list;
		list = list->next;
	}
	return (target);
}
