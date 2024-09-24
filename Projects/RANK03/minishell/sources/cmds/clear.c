/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:53:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/18 13:23:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmds_clear(t_cmds **cmds)
{
	t_cmds	*iter;
	t_cmds	*temp;

	if (cmds == NULL || *cmds == NULL)
		return ;
	iter = cmds_first(*cmds);
	while (iter != NULL)
	{
		temp = iter->next;
		if (iter->files != NULL)
			files_clear(&iter->files);
		if (iter->tokens != NULL)
			tokens_clear(&iter->tokens);
		if (iter->path != NULL)
			free(iter->path);
		if (iter->args != NULL)
			utils_freestrs(iter->args);
		free(iter);
		iter = temp;
	}
	*cmds = NULL;
}
