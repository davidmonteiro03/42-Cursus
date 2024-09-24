/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:25:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/24 14:08:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	newprompt(int sig)
{
	g_exit_status = sig + 128;
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_redisplay();
}

static void	quitchild(int sig)
{
	t_shell	*backup;

	g_exit_status = sig + 128;
	backup = shell_backup(NULL);
	ft_putchar_fd('\n', STDERR_FILENO);
	shell_hardreset(backup);
	exit(g_exit_status);
}

static void	quitmsg(int sig)
{
	g_exit_status = sig + 128;
	if (sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

static void	quitfork(int sig)
{
	t_shell	*backup;

	g_exit_status = sig + 128;
	backup = shell_backup(NULL);
	shell_hardreset(backup);
	exit(g_exit_status);
}

void	signals_handler(t_shell *shell, t_mode mode)
{
	shell_backup(shell);
	signal(SIGPIPE, SIG_DFL);
	if (mode == DEFAULT_MODE)
		return (signal(SIGINT, newprompt), signal(SIGQUIT, SIG_IGN), (void)0);
	if (mode == FORK_MODE)
		return (signal(SIGINT, quitchild), signal(SIGQUIT, quitchild),
			signal(SIGPIPE, quitfork), (void)0);
	if (mode == HEREDOC_MODE)
		return (signal(SIGINT, quitchild), signal(SIGQUIT, SIG_IGN), (void)0);
	if (mode == CONTINUE_MODE)
		return (signal(SIGINT, quitmsg), signal(SIGQUIT, quitmsg), (void)0);
	if (mode == IGNORE_MODE)
		return (signal(SIGINT, SIG_IGN), signal(SIGQUIT, SIG_IGN), (void)0);
}
