/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openclosefds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:37:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 09:15:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmds_openclosefds(t_cmds *cmds, int option)
{
	t_cmds	*iter;

	if (cmds == NULL || option < 1 || option > 2)
		return (EXIT_FAILURE);
	iter = cmds_first(cmds);
	while (iter != NULL)
	{
		if (option == 1)
		{
			if (pipe(iter->pipefd) == -1)
				return (utils_syscallerror("pipe"));
		}
		else
		{
			if (iter->pipefd[0] != -1)
				close(iter->pipefd[0]);
			if (iter->pipefd[1] != -1)
				close(iter->pipefd[1]);
		}
		iter = iter->next;
	}
	return (EXIT_SUCCESS);
}
