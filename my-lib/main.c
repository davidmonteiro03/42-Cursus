/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 09:47:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static void	echo(t_test *t)
{
	t->utils->new_line = true;
	t->utils->i = 0;
	if (strcmp(t->args[1], "-n") == 0)
	{
		t->utils->new_line = false;
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

static void	ft_argsprint(t_test *t)
{
	t->args = ft_split(t->buf, '\n');
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
	echo(t);
	multiple_free("%b", t->args);
}

int	main(void)
{
	t_test	*test;

	test = (t_test *)malloc(sizeof(t_test));
	test->utils = (t_utils *)malloc(sizeof(t_utils));
	test->line = readline("command $ ");
	test->line = buildfree(test->line, " ", &ft_strtrim);
	test->utils->i = -1;
	test->utils->len = ft_mnstrlen(test);
	test->buf = (char *)malloc(sizeof(char) * test->utils->len + 1);
	test->buf[test->utils->len] = '\0';
	test->tmp_i = 0;
	test->utils->i = -1;
	ft_strbuild(test);
	ft_argsprint(test);
	multiple_free("%a%a%a%a",
		test->buf, \
		test->line, \
		test->utils, \
		test \
	);
	return (0);
}
