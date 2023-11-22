/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 09:22:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

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
	test->args = ft_split(test->buf, '\n');
	test->utils->i = -1;
	while (test->args[++test->utils->i])
		printf("%s\n", test->args[test->utils->i]);
	multiple_free("%b%a%a%a%a", \
		test->args, \
		test->buf, \
		test->line, \
		test->utils, \
		test \
	);
	return (0);
}
