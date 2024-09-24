/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:34:17 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 11:53:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_unset(t_vars **vars, char *const key)
{
	t_vars	*iter;

	if (vars == NULL || *vars == NULL || key == NULL)
		return ;
	iter = vars_first(*vars);
	while (iter != NULL)
	{
		if (utils_strcmp(iter->key, key) == 0)
		{
			vars_remove(vars, iter);
			iter = *vars;
		}
		else
			iter = iter->next;
	}
}
