/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nopipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:25:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 20:47:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	executeredirs(t_files *lastin, t_files *lastout, t_cmds *cmd,
		t_shell *shell)
{
	if (cmd == NULL || shell == NULL)
		return ;
	shell->temp.redirfd[0] = dup(STDIN_FILENO);
	shell->temp.redirfd[1] = dup(STDOUT_FILENO);
	if (lastin != NULL)
	{
		dup2(lastin->fd, STDIN_FILENO);
		close(lastin->fd);
	}
	if (lastout != NULL)
	{
		dup2(lastout->fd, STDOUT_FILENO);
		close(lastout->fd);
	}
	builtins_execute(cmd, shell, true);
	dup2(shell->temp.redirfd[0], STDIN_FILENO);
	dup2(shell->temp.redirfd[1], STDOUT_FILENO);
	close(shell->temp.redirfd[0]);
	close(shell->temp.redirfd[1]);
}

void	cmds_nopipe(t_shell *shell)
{
	t_files	*lastin;
	t_files	*lastout;
	t_cmds	*cmd;

	if (shell == NULL || shell->cmds == NULL)
		return ;
	cmd = cmds_first(shell->cmds);
	if (cmds_checkfiles(&shell->env, cmd->files) == EXIT_SUCCESS)
	{
		lastin = files_lastin(cmd->files);
		lastout = files_lastout(cmd->files);
		if (lastin == NULL && lastout == NULL)
			return (builtins_execute(cmd, shell, true));
		executeredirs(lastin, lastout, cmd, shell);
	}
}
