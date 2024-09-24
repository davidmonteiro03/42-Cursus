/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   softreset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:44:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_softreset(t_shell *shell)
{
	if (shell == NULL)
		return ;
	if (shell->tokens != NULL)
		tokens_clear(&shell->tokens);
	if (shell->cmds != NULL)
		cmds_clear(&shell->cmds);
	temp_clear(&shell->temp);
}
