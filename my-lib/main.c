/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

typedef struct s_utils
{
	int	i;
}t_utils;

typedef struct t_test
{
	char	*line;
	t_utils	*utils;
}t_test;

int	main(int ac, char **av, char **env)
{
	t_test	*test;

	(void)ac;
	(void)av;
	(void)env;
	if (ac != 1 || av[1])
		return (0);
	test = (t_test *)malloc(sizeof(t_test));
	if (!test)
		return (1);
	test->utils = (t_utils *)malloc(sizeof(t_utils));
	if (!test->utils)
		return (free(test), 1);
	test->line = readline("command $ ");
	if (!test->line)
		return (1);
	if (!*test->line)
		return (free(test->utils), free(test->line), free(test), 0);
	test->line = buildfree(test->line, " ", &ft_strtrim);
	test->utils->i = -1;
	while (test->line[++test->utils->i])
	{
		if (test->line[test->utils->i] == '\'')
		{
			while (test->line[++test->utils->i] && \
				test->line[test->utils->i] != '\'')
				write(1, &test->line[test->utils->i], 1);
			continue ;
		}
		if (test->line[test->utils->i] == '\"')
		{
			while (test->line[++test->utils->i] && \
				test->line[test->utils->i] != '\"')
				write(1, &test->line[test->utils->i], 1);
			continue ;
		}
	}
	free(test->line);
	free(test->utils);
	free(test);
	return (0);
}
