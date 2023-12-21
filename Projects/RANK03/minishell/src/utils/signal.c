/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:34:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	handle_heardoc(int pid)
{
	int	status;

	status = 0;
	if (waitpid(pid, &status, 0) == -1)
		ft_fprintf(2, "Waitpid failed");
	else
	{
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			status = 128 + WTERMSIG(status);
	}
	get_exit_code(status, 1);
	if (status == 2)
		s_exit_minishell();
	return (status);
}

void	sig_heardoc(int sig)
{
	(void)sig;
	ft_fprintf(2, "\n");
	get_exit_code(130, 1);
	s_exit_minishell();
}

void	sig_fork(int sig)
{
	(void)sig;
	ft_fprintf(2, "\n");
	get_exit_code(130, 1);
}

void	sig_handler(int sig)
{
	get_exit_code(130, 1);
	if (sig == SIGINT)
	{
		ft_fprintf(2, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
