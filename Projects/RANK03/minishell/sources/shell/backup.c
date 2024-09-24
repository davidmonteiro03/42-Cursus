/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:22:28 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_shell	*shell_backup(t_shell *shell)
{
	static t_shell	*shell_ptr = NULL;

	if (shell != NULL)
		shell_ptr = shell;
	return (shell_ptr);
}
