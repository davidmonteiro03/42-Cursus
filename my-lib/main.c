/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 19:25:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

typedef struct s_utils
{
	int		i;
	int		j;
	char	*tmp;
	int		tmp_i;
}t_utils;

typedef struct t_test
{
	char	*line;
	t_utils	*utils;
}t_test;

void	print_str(t_test *t)
{
	t->utils->tmp = ft_substr(t->line, t->utils->j, t->utils->i - t->utils->j);
	printf("%s", t->utils->tmp);
	free(t->utils->tmp);
}

void	analyse(t_test *t)
{
	while (t->line[++t->utils->i])
	{
		if (t->line[t->utils->i] == '\'')
		{
			while (t->line[++t->utils->i] && \
				t->line[t->utils->i] != '\'')
				printf("%c", t->line[t->utils->i]);
			continue ;
		}
		if (t->line[t->utils->i] == '\"')
		{
			t->utils->j = t->utils->i + 1;
			while (t->line[++t->utils->i] && \
				t->line[t->utils->i] != '\"')
				;
			print_str(t);
			continue ;
		}
		if (t->line[t->utils->i] == ' ' && t->line[t->utils->i - 1] != ' ')
			printf(" ");
		else if (t->line[t->utils->i] != ' ')
			printf("%c", t->line[t->utils->i]);
	}
	printf("$\n");
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
	analyse(test);
	multiple_free("%a%a%a", test->line, test->utils, test);
	return (0);
}
