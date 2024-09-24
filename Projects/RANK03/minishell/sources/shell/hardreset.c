/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardreset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:02:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 08:51:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_hardreset(t_shell *shell)
{
	if (shell == NULL)
		return ;
	if (shell->line != NULL)
		free(shell->line);
	env_clear(&shell->env);
	shell_softreset(shell);
}
