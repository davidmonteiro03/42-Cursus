/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:25:15 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:34:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_ps(t_node **stack_a, t_node **stack_b, int pos[2], int mode)
{
	if (mode == 0 || mode == 1)
		exec_smt(stack_a, stack_b, pos, mode);
	else if (mode == 2)
	{
		multi_execute(stack_a, stack_b, "ra", pos[0]);
		multi_execute(stack_a, stack_b, "rrb", stacksize(*stack_b) - pos[1]);
	}
	else if (mode == 3)
	{
		multi_execute(stack_a, stack_b, "rra", stacksize(*stack_a) - pos[0]);
		multi_execute(stack_a, stack_b, "rb", pos[1]);
	}
}

void	sort3(t_node *stack_a)
{
	if (stack_a->content > stack_a->next->content)
	{
		if (stack_a->content < stack_a->next->next->content)
			execute(&stack_a, NULL, "sa", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "rra", false);
		}
		else
			execute(&stack_a, NULL, "ra", false);
	}
	else if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->content > stack_a->next->next->content)
			execute(&stack_a, NULL, "rra", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "ra", false);
		}
	}
}

void	simple_sort(t_node *stack_a, t_node *stack_b, int size)
{
	int	tmp;

	tmp = size;
	while (tmp-- > 3)
	{
		pushminmax(stack_a, false);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort3(stack_a);
	multi_execute(&stack_a, &stack_b, "pa", size - 3);
}

void	sort(t_node *stack_a, t_node *stack_b)
{
	int	i;
	int	pos[2];
	int	mode;

	multi_execute(&stack_a, &stack_b, "pb", 2);
	while (stacksize(stack_a) > 3)
	{
		pos[0] = find_min_index(stack_a, stack_b, stacksize(stack_a));
		i = -1;
		while (++i < pos[0])
			stack_a = stack_a->next;
		pos[1] = execute_calc(stack_a, stack_b, stacksize(stack_a), true);
		mode = lcm(pos, stacksize(stack_a), stacksize(stack_b), true);
		if (mode == 1)
			reverse_pos(&stack_a, &stack_b, pos);
		execute_ps(&stack_a, &stack_b, pos, mode);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort3(stack_a);
	while (stacksize(stack_b) > 0)
	{
		push_target(stack_a, find_target(stack_b, stack_a));
		execute(&stack_a, &stack_b, "pa", false);
	}
	pushminmax(stack_a, false);
}

void	push_swap(t_node *stack_a, t_node *stack_b, int size)
{
	stack_a = frstlastnode(stack_a, false);
	if (sorted(stack_a, false))
		return ;
	if (size == 2)
		execute(&stack_a, NULL, "sa", false);
	else if (size == 3)
		sort3(stack_a);
	else if (size > 3 && size < 6)
		simple_sort(stack_a, stack_b, size);
	else
		sort(stack_a, stack_b);
}
