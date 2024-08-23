/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:18:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/23 08:36:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	default_test(int (*print)(const char *, ...))
{
	int	ret;

	if (print == NULL || (print != printf && print != ft_printf))
		return ;
	if (print == printf)
		printf("=== PRINTF ===\n");
	else
		printf("=== FT_PRINTF ===\n");
	printf("--- output ---\n");
	ret = print("%s %d %x %d %s\n", (char *) NULL, 42, 42, 100, "Hello World!");
	printf("--- return ---\n");
	printf("ret = %d\n", ret);
	printf("\n");
	if (print == printf)
		fflush(stdout);
}

// add more tests here ...

static void	execute(void (*test)(int (*print)(const char *, ...)))
{
	if (test == NULL)
		return ;
	test(printf);
	test(ft_printf);
}

int	main(void)
{
	execute(default_test);
	return (0);
}
