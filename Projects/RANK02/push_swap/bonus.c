/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:28:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 10:12:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_check	check;
	bool	has_flag;

	if (argc < 2)
		return (EXIT_SUCCESS);
	has_flag = false;
	ft_parse_bonus(argv + 1, &has_flag);
	list_a = NULL;
	list_b = NULL;
	ft_fill_bonus(&list_a, argv + 1);
	ft_checkdups(list_a);
	check = (t_check){0};
	check.original_size = ft_lstsize(list_a);
	if (has_flag == true && list_a == NULL)
		ft_error();
	ft_checker_bonus(&check, &list_a, &list_b, has_flag);
	if (ft_issorted(list_a) == true && list_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&list_a, &free_content);
	ft_lstclear(&list_b, &free_content);
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
