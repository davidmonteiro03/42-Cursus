/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 17:27:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

typedef struct s_utils
{
	int	i;
	int	j;
}t_utils;

typedef struct t_test
{
	char	*line;
	t_utils	*utils;
}t_test;

void	analyse(t_test *t)
{
	while (t->line[++t->utils->i])
	{
		if (t->line[t->utils->i] == '\'')
		{
			while (t->line[++t->utils->i] && \
				t->line[t->utils->i] != '\'')
				write(1, &t->line[t->utils->i], 1);
			continue ;
		}
		if (t->line[t->utils->i] == '\"')
		{
			t->utils->j = t->utils->i + 1;
			while (t->line[++t->utils->i] && \
				t->line[t->utils->i] != '\"')
				write(1, &t->line[t->utils->i], 1);
			printf("%s", ft_substr(t->line, t->line[t->utils->j], \
				t->line[t->utils->i] - t->line[t->utils->j]));
			continue ;
		}
		if (t->line[t->utils->i] == ' ' && t->line[t->utils->i - 1] != ' ')
			write(1, " ", 1);
		else if (t->line[t->utils->i] != ' ')
			write(1, &t->line[t->utils->i], 1);
	}
	write(1, "$\n", 2);
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
