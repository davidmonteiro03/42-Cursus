/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:47:55 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmds_pushfront(t_cmds **cmds, t_cmds *node)
{
	t_cmds	*first;

	if (cmds == NULL || node == NULL)
		return ;
	if (*cmds == NULL)
		return (*cmds = node, (void)0);
	first = cmds_first(*cmds);
	first->prev = node;
	node->next = first;
	*cmds = node;
}
