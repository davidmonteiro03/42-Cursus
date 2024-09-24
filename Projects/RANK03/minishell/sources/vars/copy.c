/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:59:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_vars	*vars_copy(t_vars *const vars, void (*insert)(t_vars **, t_vars *))
{
	t_vars	*iter;
	t_vars	*copy;
	t_vars	*node;

	if (vars == NULL || insert == NULL)
		return (NULL);
	copy = NULL;
	iter = vars_first(vars);
	while (iter != NULL)
	{
		node = vars_dup(iter);
		if (node == NULL)
			return (vars_clear(&copy), NULL);
		insert(&copy, node);
		iter = iter->next;
	}
	return (copy);
}
