/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:59:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 07:16:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_init(t_shell *shell, char *const *envp)
{
	if (shell == NULL)
		return ;
	shell->line = NULL;
	env_init(&shell->env, envp, vars_pushback);
	shell->tokens = NULL;
	shell->cmds = NULL;
	temp_init(&shell->temp);
}
