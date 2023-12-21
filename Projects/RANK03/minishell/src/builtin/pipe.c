/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:29:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pipe_exec_w(int *fds, int pipe_fd[2], t_input *input)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_handler);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		free(fds);
		if (!exec(input))
		{
			get_exit_code(0, 1);
			s_exit_minishell();
		}
		get_exit_code(1, 1);
		s_exit_minishell();
	}
	close(pipe_fd[1]);
	return (pid);
}

int	pipe_exec_rw(int *fds, int pipe_fd[4],
	t_input *input)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_handler);
		close(pipe_fd[2]);
		dup2(pipe_fd[0], 0);
		dup2(pipe_fd[3], 1);
		close(pipe_fd[0]);
		close(pipe_fd[3]);
		free(fds);
		if (!exec(input))
		{
			get_exit_code(0, 1);
			s_exit_minishell();
		}
		get_exit_code(1, 1);
		s_exit_minishell();
	}
	close(pipe_fd[0]);
	close(pipe_fd[3]);
	return (pid);
}

int	pipe_exec_r(int *fds, int pipe_fd[2], t_input *input)
{
	int	pid;

	close(pipe_fd[1]);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_handler);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		free(fds);
		if (!exec(input))
		{
			get_exit_code(0, 1);
			s_exit_minishell();
		}
		get_exit_code(1, 1);
		s_exit_minishell();
	}
	close(pipe_fd[0]);
	return (pid);
}

void	pipe_loop(int *pipe_fd, t_input	*input)
{
	int		i;
	int		pipe_count;
	int		pid;

	i = 0;
	pipe_count = list_len_input(input) - 1;
	while (i < pipe_count)
	{
		pipe(pipe_fd + (i * 2));
		if (i == 0)
			pipe_exec_w(pipe_fd, pipe_fd, input);
		else
			pipe_exec_rw(pipe_fd, pipe_fd + ((i - 1) * 2), input);
		input = input->next;
		i++;
	}
	pid = pipe_exec_r(pipe_fd, pipe_fd + ((i - 1) * 2), input);
	i = -1;
	handle_error(pid);
	while (wait(NULL) != -1)
		;
}

void	pipe_exec(t_mini *mini)
{
	t_input	*input;
	t_input	*tmp;
	int		*pipe_fd;
	int		pipe_count;

	input = mini->input;
	tmp = input;
	if (!input->next)
	{
		redirects_heardoc(tmp);
		exec(input);
		return ;
	}
	while (tmp)
	{
		redirects_heardoc(tmp);
		tmp = tmp->next;
	}
	pipe_count = list_len_input(mini->input) - 1;
	pipe_fd = malloc(sizeof(int) * (pipe_count * 2));
	signal(SIGINT, sig_fork);
	pipe_loop(pipe_fd, input);
	free(pipe_fd);
}
