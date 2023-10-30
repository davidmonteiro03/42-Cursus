/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:11:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/27 08:33:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	free_ult(char *line, t_node *stack_a, t_node *stack_b)
{
	if (line)
		free(line);
	lstfree(stack_b);
	errorlst(stack_a);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*line;
	char	*command;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strchr(line, '\n') == NULL)
			free_ult(line, *stack_a, *stack_b);
		command = ft_strtrim(line, "\n");
		free(line);
		if (!command)
			free_ult(line, *stack_a, *stack_b);
		if (execute(stack_a, stack_b, command, true) == false)
			free_ult(command, *stack_a, *stack_b);
		free(command);
		line = get_next_line(0);
	}
	if (sorted(*stack_a, false) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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
	checker(&stack_a, &stack_b);
	lstfree(stack_a);
	lstfree(stack_b);
	return (0);
}
