/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 14:24:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib.h"

static void	ft_execute(t_test *t)
{
	t->utils->new_line = TRUE;
	t->utils->i = 0;
	if (strcmp(t->args[1], "-n") == 0)
	{
		t->utils->new_line = FALSE;
		t->utils->i = 1;
	}
	while (t->args[++t->utils->i])
	{
		printf("%s", t->args[t->utils->i]);
		if (t->args[t->utils->i + 1])
			printf(" ");
	}
	if (t->utils->new_line)
		printf("\n");
}

static void	ft_analyse(t_test *t)
{
	t->args = ft_split(t->buf, '\a');
	if (strcmp(t->args[0], "echo") != 0)
	{
		printf("bash: %s: command not found\n", t->args[0]);
		return (multiple_free("%b", t->args));
	}
	if (!t->args[1])
	{
		printf("\n");
		return (multiple_free("%b", t->args));
	}
	ft_execute(t);
	multiple_free("%b", t->args);
}

static void	ft_sendtotrash(t_test *t, int pro)
{
	if (pro == 1)
		multiple_free("%a%a%a%a%a", \
			t->buf, t->check, t->utils, t->line, t \
		);
	else if (pro == 0)
	{
		printf("You don't know how to use quotes, do you? 😑\n");
		multiple_free("%a%a%a%a", \
			t->check, t->utils, t->line, t \
		);
	}
}

static int	ft_quotes(t_test *t)
{
	t->utils->i = -1;
	t->check->status = FALSE;
	t->check->c = 0;
	while (t->line[++t->utils->i])
	{
		if (!t->check->status && (t->line[t->utils->i] == '\"' || \
			t->line[t->utils->i] == '\''))
		{
			t->check->status = TRUE;
			t->check->c = t->line[t->utils->i];
			continue ;
		}
		if (t->check->status && t->line[t->utils->i] == t->check->c)
		{
			t->check->status = FALSE;
			t->check->c = 0;
			continue ;
		}
	}
	return (t->check->status);
}

int	main(void)
{
	t_test	*test;

	test = (t_test *)malloc(sizeof(t_test));
	test->line = readline("command $ ");
	if (!test->line)
		return (free(test), 0);
	test->utils = (t_utils *)malloc(sizeof(t_utils));
	test->check = (t_check *)malloc(sizeof(t_check));
	if (ft_quotes(test))
		return (ft_sendtotrash(test, FALSE), 0);
	test->line = buildfree(test->line, " ", &ft_strtrim);
	test->utils->i = -1;
	test->utils->len = ft_mnstrlen(test);
	test->buf = (char *)malloc(sizeof(char) * test->utils->len + 1);
	test->buf[test->utils->len] = '\0';
	test->tmp_i = 0;
	test->utils->i = -1;
	ft_strbuild(test);
	if (!test->buf || !*test->buf)
		return (ft_sendtotrash(test, TRUE), 0);
	ft_analyse(test);
	ft_sendtotrash(test, TRUE);
	return (0);
}
