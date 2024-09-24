/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:30:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:30:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_sort(t_vars *vars)
{
	char	*temp;
	t_vars	*iter;

	if (vars == NULL)
		return ;
	iter = vars_first(vars);
	while (iter != NULL && iter->next != NULL)
	{
		if (utils_strcmp(iter->key, iter->next->key) > 0)
		{
			temp = iter->key;
			iter->key = iter->next->key;
			iter->next->key = temp;
			temp = iter->value;
			iter->value = iter->next->value;
			iter->next->value = temp;
			iter = vars_first(vars);
		}
		else
			iter = iter->next;
	}
}
