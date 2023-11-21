/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 09:09:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

typedef struct s_quotes
{
	int		count;
	int		index;
	char	*buf;
	char	*line;
}t_quotes;

void	count_chars(t_quotes *q, int status, char c)
{
	int	i;

	i = -1;
	while (q->line[++i])
	{
		if (status == 0 && (q->line[i] == '\'' || q->line[i] == '\"'))
		{
			status = 1;
			c = q->line[i];
			continue ;
		}
		if (status == 1 && q->line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if ((q->line[i] == ' ' && q->line[i - 1] != ' ' && status == 0) || \
			((q->line[i] != ' ' && status == 0) || status == 1))
			q->count++;
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

void	build_str(int j, t_quotes *q, char c)
{
	int	i;
	int	status;

	status = 0;
	i = -1;
	while (q->line[++i])
	{
		if (status == 0 && (q->line[i] == '\'' || q->line[i] == '\"'))
		{
			status = 1;
			c = q->line[i];
			continue ;
		}
		if (status == 1 && q->line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if ((q->line[i] == ' ' && q->line[i - 1] != ' ' && status == 0) || \
			((q->line[i] != ' ' && status == 0) || status == 1))
			q->buf[j++] = get_char(q->line, status, i);
	}
}

void	analyse(t_quotes *q)
{
	char	**args;
	int		i;

	args = ft_split(q->buf, '\n');
	i = -1;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	printf("\n");
	multiple_free("%b", args);
}

int	main(void)
{
	t_quotes	q;

	q.line = readline("minishell$ ");
	q.line = buildfree(q.line, " ", &ft_strtrim);
	q.count = 0;
	count_chars(&q, 0, 0);
	q.buf = malloc(sizeof(char *) * (q.count + 1));
	q.index = 0;
	build_str(0, &q, 0);
	free(q.line);
	q.buf[q.count] = '\0';
	analyse(&q);
	free(q.buf);
	return (0);
}
