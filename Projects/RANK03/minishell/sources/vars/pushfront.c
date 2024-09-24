/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:22:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:30:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_pushfront(t_vars **vars, t_vars *node)
{
	t_vars	*first;

	if (vars == NULL || node == NULL)
		return ;
	if (*vars == NULL)
		return (*vars = node, (void)0);
	first = vars_first(*vars);
	first->prev = node;
	node->next = first;
	*vars = node;
}
