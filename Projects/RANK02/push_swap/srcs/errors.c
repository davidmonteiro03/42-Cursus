/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:02:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 18:34:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	errorargs(char **strs)
{
	ft_putendl_fd("Error", 2);
	freechars(strs);
	exit(EXIT_FAILURE);
}

void	errorall(int *tab, char **strs)
{
	ft_putendl_fd("Error", 2);
	free(tab);
	freechars(strs);
	exit(EXIT_FAILURE);
}

void	errorlst(t_node *stack)
{
	ft_putendl_fd("Error", 2);
	lstfree(stack);
	exit(EXIT_FAILURE);
}
