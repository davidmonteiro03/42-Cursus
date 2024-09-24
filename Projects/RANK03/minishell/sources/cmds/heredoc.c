/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:58:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 09:13:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	unexpected_eof(char *const value)
{
	if (value == NULL)
		return ;
	display_fprintf(STDERR_FILENO, NAME);
	display_fprintf(STDERR_FILENO, ": warning");
	display_fprintf(STDERR_FILENO, ": here-document delimited by end-of-file");
	display_fprintf(STDERR_FILENO, " (wanted `%s')\n", value);
}

static void	heredoc(t_shell *shell, int fd, char *const value)
{
	char	*input;

	if (shell == NULL || fd == -1 || value == NULL)
		return ;
	shell->temp.word = parse_quotes(value);
	if (shell->temp.word == NULL)
		return ;
	input = readline("> ");
	while (input != NULL && utils_strcmp(input, shell->temp.word) != 0)
	{
		parse_heredocexpand(fd, &shell->env, input);
		free(input);
		input = readline("> ");
	}
	if (input == NULL)
		unexpected_eof(shell->temp.word);
}

int	cmds_heredoc(t_shell *shell, t_cmds *node, char *const value)
{
	if (shell == NULL || node == NULL || value == NULL)
		return (EXIT_FAILURE);
	if (pipe(shell->temp.pipefd) == -1)
		return (utils_syscallerror("pipe"));
	shell->temp.pid = fork();
	if (shell->temp.pid == -1)
		return (close(shell->temp.pipefd[1]), close(shell->temp.pipefd[0]),
			utils_syscallerror("fork"));
	files_pushback(&node->files, files_new(HEREDOC_TYPE, NULL));
	if (shell->temp.pid == 0)
	{
		signals_handler(shell, HEREDOC_MODE);
		close(shell->temp.pipefd[0]);
		heredoc(shell, shell->temp.pipefd[1], value);
		close(shell->temp.pipefd[1]);
		shell_hardreset(shell);
		exit(EXIT_SUCCESS);
	}
	signals_handler(shell, IGNORE_MODE);
	signals_status(shell->temp.pid);
	close(shell->temp.pipefd[1]);
	files_last(node->files)->fd = dup(shell->temp.pipefd[0]);
	close(shell->temp.pipefd[0]);
	return (signals_handler(shell, DEFAULT_MODE), g_exit_status);
}
