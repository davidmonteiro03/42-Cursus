/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 07:55:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

typedef struct s_utils
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp_2;
	int		tmp_i;
	int		tmp_j;
	int		print_count;
}t_utils;

typedef struct t_test
{
	char	*line;
	t_utils	*utils;
}t_test;

void	print_str(t_test *t)
{
	t->utils->tmp = ft_substr(t->line, t->utils->j, t->utils->i - t->utils->j);
	t->utils->tmp_i = -1;
	while (t->utils->tmp[++t->utils->tmp_i])
	{
		if (t->utils->tmp[t->utils->tmp_i] == '$' && \
			ft_isalnum(t->utils->tmp[t->utils->tmp_i + 1]))
		{
			t->utils->tmp_j = t->utils->tmp_i + 1;
			while (t->utils->tmp[t->utils->tmp_i + 1] && \
				ft_isalnum(t->utils->tmp[t->utils->tmp_i + 1]))
				t->utils->tmp_i++;
			t->utils->tmp_2 = ft_substr(t->utils->tmp, t->utils->tmp_j, \
				t->utils->tmp_i - t->utils->tmp_j + 1);
			if (getenv(t->utils->tmp_2))
				t->utils->print_count += printf("%s", getenv(t->utils->tmp_2));
			free(t->utils->tmp_2);
			continue ;
		}
		t->utils->print_count += printf("%c", t->utils->tmp[t->utils->tmp_i]);
	}
	free(t->utils->tmp);
}

void	analyse_op(t_test *t, int op)
{
	if (op == 1)
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\'')
			t->utils->print_count += printf("%c", t->line[t->utils->i]);
	else if (op == 2)
	{
		t->utils->j = t->utils->i + 1;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\"')
			;
		print_str(t);
	}
	else if (op == 3)
	{
		t->utils->j = t->utils->i;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != ' ' && \
			t->line[t->utils->i] != '\'' && t->line[t->utils->i] != '\"')
			;
		print_str(t);
		t->utils->i--;
	}
}

void	analyse(t_test *t)
{
	while (t->line[++t->utils->i])
	{
		if (t->line[t->utils->i] == '\'')
		{
			analyse_op(t, 1);
			continue ;
		}
		if (t->line[t->utils->i] == '\"')
		{
			analyse_op(t, 2);
			continue ;
		}
		if (t->line[t->utils->i] == ' ' && t->line[t->utils->i - 1] != ' ')
			t->utils->print_count += printf(" ");
		else if (t->line[t->utils->i] != ' ')
			analyse_op(t, 3);
	}
}

int	main(int ac, char **av, char **env)
{
	t_test	*test;

	(void)ac;
	(void)av;
	(void)env;
	test = (t_test *)malloc(sizeof(t_test));
	test->utils = (t_utils *)malloc(sizeof(t_utils));
	test->line = readline("command $ ");
	test->line = buildfree(test->line, " ", &ft_strtrim);
	test->utils->i = -1;
	test->utils->print_count = 0;
	analyse(test);
	printf("$\n");
	printf("print_count: %d\n", test->utils->print_count);
	multiple_free("%a%a%a", test->line, test->utils, test);
	return (0);
}
