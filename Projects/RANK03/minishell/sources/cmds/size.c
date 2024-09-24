/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:00:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 16:49:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	cmds_size(t_cmds *const cmds)
{
	size_t	size;
	t_cmds	*iter;

	if (cmds == NULL)
		return (0);
	size = 0;
	iter = cmds_first(cmds);
	while (iter != NULL)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}
