/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:59:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_error(pid_t pid)
{
	int	status;

	status = 0;
	if (waitpid(pid, &status, 0) == -1)
		ft_fprintf(2, "Waitpid failed");
	else
	{
		if (WIFEXITED(status))
			get_exit_code(WEXITSTATUS(status), 1);
		else if (WIFSIGNALED(status))
			get_exit_code(128 + WTERMSIG(status), 1);
		else
			get_exit_code(-42, 1);
	}
	return (get_exit_code(0, 0));
}
