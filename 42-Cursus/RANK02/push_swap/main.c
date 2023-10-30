/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:58:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 15:51:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_data	preparelist(int ac, char **av)
{
	char	**strs;
	t_data	strct;

	strs = jointsplit(ac - 1, av + 1);
	validargs(strs);
	strct.tab = validnums(strs);
	strct.size = getlen(strs);
	freechars(strs);
	return (strct);
}

int	main(int ac, char **av)
{
	t_data	strct;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	if (ac < 2)
		return (0);
	strct = preparelist(ac, av);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < strct.size)
		stack_a = addnode(stack_a, strct.tab[i++]);
	free(strct.tab);
	push_swap(stack_a, stack_b, stacksize(stack_a));
	lstfree(stack_a);
	lstfree(stack_b);
	return (0);
}
