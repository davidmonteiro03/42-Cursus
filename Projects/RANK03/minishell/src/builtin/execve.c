/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:19:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_after_exec(char **pargs)
{
	int	i;

	i = 0;
	while (pargs[i])
	{
		free(pargs[i]);
		i++;
	}
	free(pargs);
}

int	verify_2(char *path)
{
	struct stat	buf;

	if (access(path, F_OK))
	{
		ft_fprintf(2, "bash: %s: command not found\n", path);
		return (get_exit_code(127, 1), 1);
	}
	if (access(path, X_OK))
	{
		ft_fprintf(2, "bash: %s: command not found\n", path);
		return (get_exit_code(127, 1), 1);
	}
	if (stat(path, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			ft_fprintf(2, "bash: %s: command not found\n", path);
			return (get_exit_code(127, 1), 1);
		}
	}
	return (0);
}

static char	*verify(char *cmd)
{
	char		*path;
	struct stat	buf;

	path = ft_strdup(verify_access(cmd));
	if (ft_strchr(path, '/'))
	{
		if (stat(path, &buf) == 0)
			if (S_ISDIR(buf.st_mode) == 1 && ft_fprintf(2,
					"bash: %s: Is a directory\n", path))
				return (free(path), get_exit_code(126, 1),
					s_exit_minishell(), NULL);
		if (access(path, F_OK) && ft_fprintf(2,
				"bash: %s: No such file or directory\n", path))
			return (get_exit_code(127, 1), free(path), NULL);
		if (access(path, X_OK))
			return (get_exit_code(126, 1), ft_fprintf(2, "bash: %s: \
	Permission denied\n", path), free(path), NULL);
	}
	if (verify_2(path))
		return (free(path), NULL);
	return (path);
}

static void	confirm_exec(t_mini *mini, t_input *input)
{
	char	*path;
	char	**pargs;
	int		i;

	i = 0;
	path = verify(input->command->cmd);
	if (path)
	{
		pargs = malloc(sizeof(char *) * 500);
		pargs[0] = path;
		if (input->command->args)
		{
			i = -1;
			while (input->command->args[++i])
				pargs[i + 1] = ft_strdup(input->command->args[i]);
		}
		pargs[i + 1] = NULL;
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		execve(path, pargs, mini->envp);
		free_after_exec(pargs);
	}
}

int	ft_execve(t_mini *mini, t_input *input)
{
	int		status;
	pid_t	pid;

	status = 0;
	signal(SIGINT, SIG_IGN);
	if (mini->input->next)
	{
		confirm_exec(mini, input);
		s_exit_minishell();
	}
	pid = fork();
	if (pid == 0)
	{
		confirm_exec(mini, input);
		s_exit_minishell();
	}
	status = handle_error(pid);
	if (status == 130)
		ft_fprintf(1, "\n");
	return (status);
}
