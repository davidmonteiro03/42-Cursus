/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetvalue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:15:07 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 17:20:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_resetvalue(t_vars **vars, char *const key)
{
	t_vars	*iter;

	if (vars == NULL || *vars == NULL || key == NULL)
		return ;
	iter = vars_first(*vars);
	while (iter != NULL)
	{
		if (utils_strcmp(iter->key, key) == 0 && iter->value != NULL)
		{
			free(iter->value);
			iter->value = NULL;
		}
		iter = iter->next;
	}
}
