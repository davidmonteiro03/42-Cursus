/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 08:22:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 08:03:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	waitcmds(t_shell *shell)
{
	t_cmds	*iter;

	if (shell == NULL || shell->cmds == NULL)
		return ;
	cmds_openclosefds(shell->cmds, 2);
	iter = cmds_first(shell->cmds);
	while (iter != NULL)
	{
		signals_handler(shell, CONTINUE_MODE);
		signals_status(iter->pid);
		iter = iter->next;
	}
	signals_handler(shell, DEFAULT_MODE);
}

static void	cmdspipe(t_shell *shell)
{
	t_cmds	*iter;

	if (shell == NULL)
		return ;
	iter = cmds_first(shell->cmds);
	while (iter != NULL)
	{
		iter->pid = fork();
		if (iter->pid == 0)
		{
			signals_handler(shell, FORK_MODE);
			env_underscoreup(&shell->env, utils_laststr(iter->args));
			if (cmds_checkfiles(&shell->env, iter->files) == EXIT_SUCCESS)
			{
				cmds_controlfds(iter);
				builtins_execute(iter, shell, false);
			}
			shell_hardreset(shell);
			exit(g_exit_status);
		}
		iter = iter->next;
	}
	waitcmds(shell);
}

void	cmds_execute(t_shell *shell)
{
	if (shell == NULL || cmds_size(shell->cmds) < 1)
		return ;
	if (cmds_size(shell->cmds) < 2)
		return (cmds_nopipe(shell));
	if (cmds_openclosefds(shell->cmds, 1) != EXIT_SUCCESS)
		return ;
	cmdspipe(shell);
}
