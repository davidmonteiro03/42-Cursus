/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:07:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/18 13:23:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmds	*cmds_new(void)
{
	t_cmds	*node;

	node = (t_cmds *)ft_calloc(1, sizeof(t_cmds));
	if (node == NULL)
		return (NULL);
	node->files = NULL;
	node->tokens = NULL;
	node->path = NULL;
	node->args = NULL;
	node->pid = -1;
	node->pipefd[0] = -1;
	node->pipefd[1] = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
