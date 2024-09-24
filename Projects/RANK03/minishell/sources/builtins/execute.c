/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:59:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 13:18:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_execute(t_cmds *cmd, t_shell *shell, bool need_fork)
{
	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	if (utils_strcmp(cmd->args[0], ECHO_STR) == 0)
		return (builtins_echo(cmd, shell));
	if (utils_strcmp(cmd->args[0], CD_STR) == 0)
		return (builtins_cd(cmd, shell));
	if (utils_strcmp(cmd->args[0], PWD_STR) == 0)
		return (builtins_pwd());
	if (utils_strcmp(cmd->args[0], EXPORT_STR) == 0)
		return (builtins_export(cmd, shell));
	if (utils_strcmp(cmd->args[0], UNSET_STR) == 0)
		return (builtins_unset(cmd, shell));
	if (utils_strcmp(cmd->args[0], ENV_STR) == 0)
		return (env_display(&shell->env, "=", true, false));
	if (utils_strcmp(cmd->args[0], EXIT_STR) == 0)
		return (builtins_exit(cmd, shell));
	return (builtins_execve(cmd, shell, need_fork));
}
