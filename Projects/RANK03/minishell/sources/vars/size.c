/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:00:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:30:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	vars_size(t_vars *const vars)
{
	size_t	size;
	t_vars	*iter;

	if (vars == NULL)
		return (0);
	size = 0;
	iter = vars_first(vars);
	while (iter != NULL)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}
