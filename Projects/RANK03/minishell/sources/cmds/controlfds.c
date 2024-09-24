/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlfds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:36:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 15:08:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handlefds(t_cmds *iter, bool stdinfd, bool stdoutfd)
{
	t_files	*lastin;
	t_files	*lastout;

	if (iter == NULL)
		return ;
	lastin = files_lastin(iter->files);
	lastout = files_lastout(iter->files);
	if (lastin != NULL)
		dup2(lastin->fd, STDIN_FILENO);
	else if (stdinfd == true)
		dup2(iter->prev->pipefd[0], STDIN_FILENO);
	if (lastout != NULL)
		dup2(lastout->fd, STDOUT_FILENO);
	else if (stdoutfd == true)
		dup2(iter->pipefd[1], STDOUT_FILENO);
}

void	cmds_controlfds(t_cmds *iter)
{
	if (iter == NULL)
		return ;
	if (iter->prev == NULL)
	{
		handlefds(iter, false, true);
		close(iter->pipefd[0]);
	}
	else if (iter->next == NULL)
	{
		handlefds(iter, true, false);
		close(iter->prev->pipefd[1]);
	}
	else
	{
		handlefds(iter, true, true);
		close(iter->prev->pipefd[1]);
		close(iter->pipefd[0]);
	}
	cmds_openclosefds(iter, 2);
}
