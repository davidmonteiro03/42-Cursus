/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:20:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	min_lcm(int *arr, int size, bool index)
{
	int	min;
	int	i;
	int	target_index;

	i = 0;
	target_index = 0;
	min = arr[0];
	while (++i < size)
	{
		if (arr[i] < min && arr[i] >= 0)
		{
			min = arr[i];
			target_index = i;
		}
	}
	if (index == true)
		return (target_index);
	else
		return (min);
}

int	lcm(int pos[2], int size_a, int size_b, bool move)
{
	int	nlcm[4];
	int	temp_pos_b;

	temp_pos_b = -1;
	if (pos[1] == 0)
	{
		temp_pos_b = pos[1];
		pos[1] = pos[0];
	}
	if (pos[0] < pos[1])
		nlcm[0] = pos[1];
	else
		nlcm[0] = pos[0];
	if (size_a - pos[0] < size_b - pos[1])
		nlcm[1] = (size_b - pos[1]);
	else
		nlcm[1] = (size_a - pos[0]);
	nlcm[2] = pos[0] + (size_b - pos[1]);
	nlcm[3] = (size_a - pos[0]) + pos[1];
	if (temp_pos_b != -1)
		pos[1] = temp_pos_b;
	if (move == true)
		return (min_lcm(nlcm, 4, true));
	else
		return (min_lcm(nlcm, 4, false));
}

int	calc(t_node *stack_a, t_node *stack_b, int size, bool pos_b)
{
	t_node	*tmp;
	int		nmoves_to_top[2];
	int		target;

	nmoves_to_top[0] = node_index(stack_a, stack_a->content);
	tmp = frstlastnode(stack_b, false);
	if (stack_b)
	{
		target = tmp->content;
		while (tmp)
		{
			if ((tmp->content > target && tmp->content < stack_a->content)
				|| (tmp->content < stack_a->content
					&& target > stack_a->content))
				target = tmp->content;
			tmp = tmp->next;
		}
		nmoves_to_top[1] = node_index(stack_b, target);
		if (pos_b == true)
			return (nmoves_to_top[1]);
		else
			return (lcm(nmoves_to_top, size, stacksize(stack_b), false) + 1);
	}
	return (nmoves_to_top[0] + 1);
}

int	execute_calc(t_node *stack_a, t_node *stack_b, int size, bool pos_b)
{
	int	nmoves;
	int	pos[2];

	if ((stack_a->content < posminmax(stack_b, false, false))
		|| (stack_a->content > posminmax(stack_b, true, false)))
	{
		pos[0] = node_index(stack_a, stack_a->content);
		pos[1] = posminmax(stack_b, true, true);
		if (pos_b == true)
			nmoves = pos[1];
		else
			nmoves = (lcm(pos, stacksize(stack_a), stacksize(stack_b), false)
					+ 1);
	}
	else
		nmoves = calc(stack_a, stack_b, size, pos_b);
	return (nmoves);
}

void	reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2])
{
	pos[0] = stacksize(*stack_a) - pos[0];
	if (pos[1] != 0)
		pos[1] = stacksize(*stack_b) - pos[1];
}
