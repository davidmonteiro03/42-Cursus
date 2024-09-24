/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:01:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 11:51:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_clear(t_vars **vars)
{
	t_vars	*iter;
	t_vars	*temp;

	if (vars == NULL || *vars == NULL)
		return ;
	iter = vars_first(*vars);
	while (iter != NULL)
	{
		temp = iter->next;
		vars_delone(iter);
		iter = temp;
	}
	*vars = NULL;
}
