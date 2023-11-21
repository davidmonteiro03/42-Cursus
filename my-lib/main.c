/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 14:33:19 by dcaetano         ###   ########.fr       */
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
	char	**args;
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
		if (i > 0 && ((*q)->line[i - 1] == c || (*q)->line[i + 1] == c))
			(*q)->count++;
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
		if (i > 0 && (*q)->line[i - 1] == c)
			(*q)->buf[j++] = c;
		if (((*q)->line[i] == ' ' && (*q)->line[i - 1] != ' ' && \
			status == 0) || (((*q)->line[i] != ' ' && status == 0) \
			|| status == 1))
			(*q)->buf[j++] = get_char((*q)->line, status, i);
		if ((*q)->line[i + 1] == c)
			(*q)->buf[j++] = c;
	}
}

void	check_arg(char *arg, int status, char c)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (status == 0 && (arg[i] == '\'' || arg[i] == '\"'))
		{
			status = 1;
			c = arg[i];
			continue ;
		}
		if (status == 1 && arg[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		printf("%c", arg[i]);
	}
}

void	analyse(t_quotes **q)
{
	int		i;

	(*q)->args = ft_split((*q)->buf, '\n');
	i = -1;
	while ((*q)->args[++i])
	{
		check_arg((*q)->args[i], 0, 0);
		if ((*q)->args[i + 1])
			printf(" +\n");
	}
	printf("\n");
	multiple_free("%b", (*q)->args);
}

int	main(void)
{
	t_quotes	*q;

	q = (t_quotes *)malloc(sizeof(t_quotes));
	q->line = readline("minishell$ ");
	q->line = buildfree(q->line, " ", &ft_strtrim);
	q->count = 0;
	count_chars(&q, 0, 0);
	q->buf = malloc(sizeof(char *) * (q->count + 1));
	q->index = 0;
	build_str(0, &q, 0, 0);
	q->buf[q->count] = '\0';
	analyse(&q);
	multiple_free("%a%a%a", q->line, q->buf, q);
	return (0);
}
