/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:32:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heardoc_quotes(char *line, char c, int fd)
{
	char	*str;
	int		i;

	signal(SIGINT, sig_heardoc);
	ft_fprintf(fd, "%s", line);
	while (1)
	{
		str = readline("> ");
		if (!str && ft_fprintf(2, "bash: unexpected EOF while looking for\
matching `%c'\nbash: syntax error: unexpected end of file\n", c))
			return (get_exit_code(1, 1), (void)0);
		i = 0;
		ft_fprintf(fd, "\n%s", str);
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			break ;
		free(str);
		str = NULL;
	}
	free(str);
}

int	call_heardoc_quotes(char **line, char c)
{
	int	fd_pipe[2];
	int	status;
	int	pid;

	pipe(fd_pipe);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		close(fd_pipe[0]);
		heardoc_quotes(*line, c, fd_pipe[1]);
		close(fd_pipe[1]);
		s_exit_minishell();
	}
	else
	{
		close(fd_pipe[1]);
		status = handle_heardoc(pid);
		if (status)
			return (close(fd_pipe[0]), 1);
	}
	free(*line);
	*line = read_file(fd_pipe[0]);
	return (signal(SIGINT, sig_handler), 0);
}
