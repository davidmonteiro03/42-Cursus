/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:15:18 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:36:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_unset(t_cmds *cmd, t_shell *shell)
{
	size_t	i;

	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	g_exit_status = 0;
	i = 1;
	while (cmd->args[i] != NULL)
		env_unset(&shell->env, cmd->args[i++]);
}
