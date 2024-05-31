/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:05:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 20:32:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ft_parse(argv + 1);
	list_a = NULL;
	list_b = NULL;
	ft_fill(&list_a, argv + 1);
	ft_checkdups(list_a);
	ft_sortlist(&list_a, &list_b);
	ft_lstclear(&list_a, &free_content);
	ft_lstclear(&list_b, &free_content);
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
