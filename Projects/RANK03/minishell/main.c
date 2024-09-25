/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:14:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 07:13:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			g_exit_status = EXIT_SUCCESS;

static void	execute(t_shell *shell)
{
	if (shell == NULL || shell->tokens == NULL)
		return ;
	if (syntax_parse(shell->tokens) != EXIT_SUCCESS)
		return (shell_softreset(shell));
	if (cmds_parse(shell) != EXIT_SUCCESS)
		return (shell_softreset(shell));
	cmds_execute(shell);
	shell_softreset(shell);
}

int	main(int const argc, char *const *argv, char *const *envp)
{
	t_shell	shell;

	signals_handler(&shell, DEFAULT_MODE);
	shell_init(&shell, envp);
	while (parse_readline(&shell) == true)
		execute(&shell);
	if (isatty(STDIN_FILENO))
		ft_putendl_fd("exit", STDERR_FILENO);
	rl_clear_history();
	return (shell_hardreset(&shell), (void)argc, (void)argv, (void)envp,
		g_exit_status);
}
