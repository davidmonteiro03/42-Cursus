/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:29:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 08:28:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_execute(char *op, t_list **list_a, t_list **list_b, bool print)
{
	if (print == true)
		ft_putendl_fd(op, 1);
	if (ft_strcmp(op, "sa") == 0)
		return (ft_swap(list_a));
	if (ft_strcmp(op, "sb") == 0)
		return (ft_swap(list_b));
	if (ft_strcmp(op, "ss") == 0)
		return (ft_swap(list_a), ft_swap(list_b));
	if (ft_strcmp(op, "pa") == 0)
		return (ft_push(list_b, list_a));
	if (ft_strcmp(op, "pb") == 0)
		return (ft_push(list_a, list_b));
	if (ft_strcmp(op, "ra") == 0)
		return (ft_rotate(list_a, 0));
	if (ft_strcmp(op, "rb") == 0)
		return (ft_rotate(list_b, 0));
	if (ft_strcmp(op, "rr") == 0)
		return (ft_rotate(list_a, 0), ft_rotate(list_b, 0));
	if (ft_strcmp(op, "rra") == 0)
		return (ft_rotate(list_a, 1));
	if (ft_strcmp(op, "rrb") == 0)
		return (ft_rotate(list_b, 1));
	if (ft_strcmp(op, "rrr") == 0)
		return (ft_rotate(list_a, 1), ft_rotate(list_b, 1));
	return (false);
}

void	ft_multiexecute(t_list **list_a, t_list **list_b, t_rotate *rot)
{
	if (*list_a == NULL)
		return ;
	while (rot->ops[RRR]--)
		ft_execute("rrr", list_a, list_b, true);
	while (rot->ops[RR]--)
		ft_execute("rr", list_a, list_b, true);
	while (rot->ops[RA]--)
		ft_execute("ra", list_a, list_b, true);
	while (rot->ops[RB]--)
		ft_execute("rb", list_a, list_b, true);
	while (rot->ops[RRA]--)
		ft_execute("rra", list_a, list_b, true);
	while (rot->ops[RRB]--)
		ft_execute("rrb", list_a, list_b, true);
}
