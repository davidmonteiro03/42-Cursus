/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:57:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:11:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	sorted(t_node *stack, bool reverse)
{
	t_node	*tmp;

	tmp = frstlastnode(stack, false);
	if (stacksize(stack) == 0 || !stack)
		return (false);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content && reverse == false)
			return (false);
		if (tmp->content < tmp->next->content && reverse == true)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	node_index(t_node *stack, int target)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = frstlastnode(stack, false);
	if (stacksize(stack) == 0 || !stack)
		return (-1);
	while (tmp)
	{
		if (tmp->content == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	posminmax(t_node *stack, bool max, bool pos)
{
	int		target;
	int		attr[2];
	t_node	*tmp;

	tmp = frstlastnode(stack, false);
	attr[0] = -1;
	attr[1] = 0;
	target = tmp->content;
	while (++attr[0] < stacksize(stack))
	{
		if ((tmp->content > target && max == true) || \
			(tmp->content < target && max == false))
		{
			target = tmp->content;
			attr[1] = attr[0];
		}
		tmp = tmp->next;
	}
	if (pos == true)
		return (attr[1]);
	else
		return (target);
}

void	pushminmax(t_node *stack, bool max)
{
	int	pos;

	pos = posminmax(stack, max, true);
	push_target(stack, pos);
}

int	find_min_index(t_node *stack_a, t_node *stack_b, int size)
{
	int		min;
	int		index[2];
	t_node	*tmp;

	tmp = frstlastnode(stack_a, false);
	min = execute_calc(stack_a, stack_b, size, false);
	index[0] = 0;
	index[1] = 0;
	while (tmp)
	{
		if (execute_calc(tmp, stack_b, size, false) < min)
		{
			min = execute_calc(tmp, stack_b, size, false);
			index[1] = index[0];
		}
		tmp = tmp->next;
		index[0]++;
	}
	return (index[1]);
}
