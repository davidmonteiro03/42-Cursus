/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:43:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:25:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target(t_node *stack_from, t_node *stack_to)
{
	t_node	*tmp;
	int		target;

	tmp = frstlastnode(stack_to, false);
	target = tmp->content;
	if (stack_from->content > posminmax(stack_to, true, false))
		return (posminmax(stack_to, false, true));
	while (tmp)
	{
		if ((tmp->content < target && tmp->content > stack_from->content) || \
			(tmp->content > stack_from->content && \
			target < stack_from->content))
			target = tmp->content;
		tmp = tmp->next;
	}
	return (node_index(stack_to, target));
}

void	push_target(t_node *stack, int pos)
{
	int	len;

	stack = frstlastnode(stack, false);
	len = stacksize(stack);
	if (pos <= len / 2)
	{
		while (pos--)
			execute(&stack, NULL, "ra", false);
	}
	else
	{
		pos = len - pos;
		while (pos--)
			execute(&stack, NULL, "rra", false);
	}
}

void	exec_smt(t_node **stack_a, t_node **stack_b, int pos[2], int mode)
{
	if (mode == 0)
	{
		multi_execute(stack_a, stack_b, "rr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_b, "ra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1])
			multi_execute(stack_a, stack_b, "rb", pos[1] - pos[0]);
	}
	else if (mode == 1)
	{
		multi_execute(stack_a, stack_b, "rrr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_a, "rra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1]
			&& pos[1] != 0)
			multi_execute(stack_a, stack_b, "rrb", pos[1] - pos[0]);
	}
}
