/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 16:39:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <sys/wait.h>
#include <readline/readline.h>

typedef struct s_quotes
{
	int		count;
	int		index;
	char	*buf;
	char	*line;
	char	**args;
	char	*cmd;
}t_quotes;

void	count_chars(t_quotes **q, int status, char c)
{
	int	i;

	i = -1;
	while ((*q)->line[++i])
	{
		if (status == 0 && ((*q)->line[i] == '\'' || (*q)->line[i] == '\"'))
		{
			status = 1;
			c = (*q)->line[i];
			continue ;
		}
		if (status == 1 && (*q)->line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if (((*q)->line[i] == ' ' && (*q)->line[i - 1] != ' ' \
			&& status == 0) || (((*q)->line[i] != ' ' && status == 0) \
			|| status == 1))
			(*q)->count++;
	}
}

char	get_char(char *line, int status, int i)
{
	if (((line[i] != ' ' && status == 0) || status == 1))
		return (line[i]);
	else if ((line[i] == ' ' && line[i - 1] != ' ' && status == 0))
		return ('\n');
	return (0);
}

void	build_str(int j, t_quotes **q, char c, int status)
{
	int	i;

	i = -1;
	while ((*q)->line[++i])
	{
		if (status == 0 && ((*q)->line[i] == '\'' || (*q)->line[i] == '\"'))
		{
			status = 1;
			c = (*q)->line[i];
			continue ;
		}
		if (status == 1 && (*q)->line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if (((*q)->line[i] == ' ' && (*q)->line[i - 1] != ' ' && \
			status == 0) || (((*q)->line[i] != ' ' && status == 0) \
			|| status == 1))
			(*q)->buf[j++] = get_char((*q)->line, status, i);
	}
}

void	analyse(t_quotes **q, char **env)
{
	int		size;
	char	**args;

	(*q)->args = ft_split((*q)->buf, '\n');
	size = 0;
	while ((*q)->args[size])
		size++;
	args = (char **)malloc(sizeof(char *) * (size + 1));
	args[0] = "/bin/echo";
	size = 1;
	while ((*q)->args[size])
	{
		if ((*q)->args[size][0] == '$')
		{
			args[size] = ft_strdup(((*q)->args[size]));
			args[size] = buildfree(args[size], "$", &ft_strtrim);
			args[size] = getenv(args[size]);
		}
		else
			args[size] = (*q)->args[size];
		size++;
	}
	args[size] = NULL;
	(*q)->cmd = args[0];
	if (fork() == 0)
		execve((*q)->cmd, args, env);
	else
		wait(NULL);
	free(args);
	multiple_free("%b", (*q)->args);
}

int	main(int ac, char **av, char **env)
{
	t_quotes	*q;

	(void)ac;
	(void)av;
	q = (t_quotes *)malloc(sizeof(t_quotes));
	q->line = readline("minishell$ ");
	q->line = buildfree(q->line, " ", &ft_strtrim);
	q->count = 0;
	count_chars(&q, 0, 0);
	q->buf = malloc(sizeof(char *) * (q->count + 1));
	q->index = 0;
	build_str(0, &q, 0, 0);
	q->buf[q->count] = '\0';
	analyse(&q, env);
	multiple_free("%a%a%a", q->line, q->buf, q);
	return (0);
}
