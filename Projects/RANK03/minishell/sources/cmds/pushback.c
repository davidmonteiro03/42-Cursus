/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:47:55 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmds_pushback(t_cmds **cmds, t_cmds *node)
{
	t_cmds	*last;

	if (cmds == NULL || node == NULL)
		return ;
	if (*cmds == NULL)
		return (*cmds = node, (void)0);
	last = cmds_last(*cmds);
	last->next = node;
	node->prev = last;
}
