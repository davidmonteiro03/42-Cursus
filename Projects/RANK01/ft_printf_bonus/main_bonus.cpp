/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:18:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 17:48:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
#include "ft_printf.h"
#include <stdio.h>
}

#define PRINTF_STR "/// printf ///\n"
#define FT_PRINTF_STR "/// ft_printf ///\n"
#define TEST_STR "======= test: %s =======\n"
#define OUTPUT_STR "output:"
#define RETURN_STR "|return:%d\n"
#define TYPE_c "c"
#define TYPE_s "s"
#define TYPE_p "p"
#define TYPE_d "d"
#define TYPE_i "i"
#define TYPE_u "u"
#define TYPE_x "x"
#define TYPE_X "X"
#define TYPE_percent "%"
#define TEST_c \
	"%c %-c %0c %.c %#c % c %     1     -3 c"
#define TEST_s "%-s %-s %-s %-s %-s"
#define TEST_p "%-p %-p %-p %-p %-p"
#define TEST_d "%-d %-d %-d %-d %-d %-d %-d"
#define TEST_i "%-i %-i %-i %-i %-i %-i %-i"
#define TEST_u "%-u %-u %-u %-u %-u %-u %-u"
#define TEST_x "%-x %-x %-x %-x %-x %-x %-x"
#define TEST_X "%-X %-X %-X %-X %-X %-X %-X"
#define TEST_percent "%-%"

static void test_c(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, 42, 42, 42, 42, 42, 42, 42);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_s(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, NULL, "", "\0", "42", "42\0");
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_p(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -1, NULL, 42, print, &print);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_d(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -2147483649, -2147483648, -42, 0, 42,
					2147483647, 2147483648);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_i(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -2147483649, -2147483648, -42, 0, 42,
					2147483647, 2147483648);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_u(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -1, 0, 42, 2147483647, 2147483648,
					4294967295, 4294967296);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_x(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -1, 0, 42, 2147483647, 2147483648,
					4294967295, 4294967296);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_X(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format, -1, 0, 42, 2147483647, 2147483648,
					4294967295, 4294967296);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

static void test_percent(const char *format, int (*print)(const char *, ...))
{
	if (format == NULL || print == NULL || (print != printf && print != ft_printf))
		return;
	if (print == printf)
		printf(PRINTF_STR);
	else
		printf(FT_PRINTF_STR);
	printf(OUTPUT_STR);
	fflush(stdout);
	int ret = print(format);
	printf(RETURN_STR, ret);
	if (print == printf)
		fflush(stdout);
}

// add more tests here ...

static void execute(const char *name, const char *format, void (*test)(const char *, int (*print)(const char *, ...)))
{
	if (name == NULL || test == NULL)
		return;
	printf(TEST_STR, name);
	test(format, printf);
	test(format, ft_printf);
	printf("\n");
}

int main(void)
{
	execute(TYPE_c, TEST_c, test_c);
	execute(TYPE_s, TEST_s, test_s);
	execute(TYPE_p, TEST_p, test_p);
	execute(TYPE_d, TEST_d, test_d);
	execute(TYPE_i, TEST_i, test_i);
	execute(TYPE_u, TEST_u, test_u);
	execute(TYPE_x, TEST_x, test_x);
	execute(TYPE_X, TEST_X, test_X);
	execute(TYPE_percent, TEST_percent, test_percent);
	return (0);
}
