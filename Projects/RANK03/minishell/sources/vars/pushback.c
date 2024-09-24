/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:22:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:30:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_pushback(t_vars **vars, t_vars *node)
{
	t_vars	*last;

	if (vars == NULL || node == NULL)
		return ;
	if (*vars == NULL)
		return (*vars = node, (void)0);
	last = vars_last(*vars);
	last->next = node;
	node->prev = last;
}
