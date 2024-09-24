/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:10:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:42:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_export(t_cmds *cmd, t_shell *shell)
{
	t_exp	exp;
	size_t	i;

	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	g_exit_status = 0;
	if (cmd->args[1] == NULL)
		return (env_display(&shell->env, "=", false, true));
	i = 1;
	while (cmd->args[i] != NULL)
	{
		exp_init(&exp, cmd->args[i]);
		exp_execute(&shell->env, exp, cmd->args[i++]);
		exp_clear(&exp);
	}
}
