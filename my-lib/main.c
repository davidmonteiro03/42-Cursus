/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 08:29:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

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
	test->utils->len = ft_mnstrlen(test);
	test->buf = (char *)malloc(sizeof(char) * (test->utils->len + 1));
	test->buf[test->utils->len] = '\0';
	multiple_free("%a%a%a%a", \
		test->buf, \
		test->line, \
		test->utils, \
		test \
	);
	return (0);
}
