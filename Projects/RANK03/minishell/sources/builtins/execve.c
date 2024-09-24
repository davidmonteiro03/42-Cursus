/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:05:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 08:51:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	writeerror(char *const path, char *const error)
{
	char	*output;

	if (path == NULL || error == NULL)
		return ;
	output = ft_strjoin(NAME, ": ");
	output = utils_joinfree(output, ft_strdup(path));
	output = utils_joinfree(output, ft_strdup(": "));
	output = utils_joinfree(output, ft_strdup(error));
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
}

static void	patherror(char *const path)
{
	struct stat	path_stat;
	int			stat_res;
	int			access_res;
	char		*error;

	stat_res = stat(path, &path_stat);
	access_res = access(path, X_OK);
	if (access_res == -1 && errno == EACCES)
		error = "Permission denied";
	else if (stat_res == 0 && S_ISDIR(path_stat.st_mode))
		error = "Is a directory";
	else if (access_res == -1 && errno == ENOENT)
		error = "No such file or directory";
	else
		error = strerror(errno);
	if (errno == ENOENT)
		g_exit_status = 127;
	else
		g_exit_status = 126;
	writeerror(path, error);
}

static void	ftexecve(t_cmds *cmd, t_shell *shell)
{
	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	cmd->path = builtins_getpath(cmd->args[0], &shell->env);
	if (cmd->path == NULL)
		return ;
	execve(cmd->path, cmd->args, shell->env.envp);
	patherror(cmd->path);
}

void	builtins_execve(t_cmds *cmd, t_shell *shell, bool need_fork)
{
	pid_t	pid;

	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	if (need_fork == false)
		return (ftexecve(cmd, shell));
	pid = fork();
	if (pid == 0)
	{
		signals_handler(shell, FORK_MODE);
		ftexecve(cmd, shell);
		shell_hardreset(shell);
		exit(g_exit_status);
	}
	signals_handler(shell, CONTINUE_MODE);
	signals_status(pid);
	signals_handler(shell, DEFAULT_MODE);
}
