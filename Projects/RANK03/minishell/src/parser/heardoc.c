/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:28:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pipe_heardoc(t_mini *mini, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	signal(SIGINT, sig_heardoc);
	signal(SIGQUIT, SIG_IGN);
	ft_fprintf(fd, "%s", mini->line);
	while (1)
	{
		tmp = readline("> ");
		if (!tmp && ft_fprintf(2, "bash: \
syntax error: unexpected end of file\n"))
			return (close(fd), 1);
		skip_space(tmp, &i);
		if (tmp[i] && ft_fprintf(fd, " %s", tmp))
			return (free(tmp), close(fd), 0);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int	heardoc(char *str, char **args, int fd)
{
	char	*input;

	signal(SIGINT, sig_heardoc);
	signal(SIGQUIT, SIG_IGN);
	ft_fprintf(2, "%s", str);
	while (1)
	{
		input = readline("> ");
		if (!input && ft_fprintf(2, "bash: warning: here-document \
delimited by end-of-file (wanted `%s')\n", args[1]))
			return (free_split(args), get_exit_code(2, 1), close(fd), 1);
		if (!ft_strcmp(input, args[1]))
			break ;
		input = expand_arg_adv(input, 0, 0);
		ft_fprintf(fd, "%s\n", input);
		free(input);
		input = NULL;
	}
	if (input)
		free(input);
	return (free_split(args), free(str), close(fd), 0);
}

int	call_heardoc_pipe(t_mini *mini)
{
	int	pid;
	int	fd_pipe[2];

	pipe(fd_pipe);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		if (pipe_heardoc(mini, fd_pipe[1]))
			get_exit_code(2, 1);
		else
			get_exit_code(0, 1);
		s_exit_minishell();
	}
	close(fd_pipe[1]);
	free(mini->line);
	mini->line = read_file(fd_pipe[0]);
	if (handle_heardoc(pid))
		return (1);
	return (signal(SIGINT, sig_handler), 0);
}

int	call_heardoc(char **line, char **args, t_input *input)
{
	int		pid;
	int		fd_pipe[2];
	char	*tmp;

	tmp = args[1];
	args[1] = trim_quotes(args[1]);
	free(tmp);
	pipe(fd_pipe);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		if (heardoc(*line, args, fd_pipe[1]))
			get_exit_code(2, 1);
		else
			get_exit_code(0, 1);
		s_exit_minishell();
	}
	close(fd_pipe[1]);
	input->heardoc = read_file(fd_pipe[0]);
	if (handle_error(pid))
		return (1);
	return (0);
}

void	redirects_heardoc(t_input *input)
{
	char	*tmp;
	int		i;

	tmp = input->line;
	input->line = ft_strtrim(input->line, " ");
	free(tmp);
	i = -1;
	while (input->line[++i])
	{
		if (input->line[i] == '\"' || input->line[i] == '\'')
			i += skip(input->line + i + 1, input->line[i]) + 1;
		if (input->line[i] == '<' && input->line[i + 1] == '<')
		{
			if (input->heardoc)
				free(input->heardoc);
			input->heardoc = NULL;
			if (handle_redirect(input, i))
				return ;
		}
	}
}
