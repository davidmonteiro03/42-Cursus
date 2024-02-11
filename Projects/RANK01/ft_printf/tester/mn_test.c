/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:16:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/11 00:59:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mn_test.h"

bool	same_output(const char *file1, const char *file2)
{
	FILE	*fptr1;
	FILE	*fptr2;
	int		ch1;
	int		ch2;

	fptr1 = fopen(file1, "r");
	fptr2 = fopen(file2, "r");
	ch1 = getc(fptr1);
	ch2 = getc(fptr2);
	while (ch1 != EOF && ch2 != EOF)
	{
		if (ch1 != ch2)
			return (fclose(fptr1), fclose(fptr2), false);
		ch1 = getc(fptr1);
		ch2 = getc(fptr2);
	}
	return (fclose(fptr1), fclose(fptr2), true);
}

void	test_print(int *num_tests, int limit, \
	int max_width, const char *format, ...)
{
	va_list	args;
	int		unknown_ret;
	int		correct_ret;

	if (*num_tests % limit == 0 && *num_tests != 0)
		printf("\n");
	va_start(args, format);
	va_end(args);
	freopen("unknown", "w", stdout);
	unknown_ret = ft_printf(format, args);
	freopen("correct", "w", stdout);
	correct_ret = printf(format, args);
	freopen("/dev/tty", "w", stdout);
	if (same_output("unknown", "correct") && unknown_ret == correct_ret)
		printf(OK_COLOR "%*d. OK" RESET, max_width + 1, ++(*num_tests));
	else
		printf(KO_COLOR "%*d. KO" RESET, max_width + 1, ++(*num_tests));
	remove("unknown");
	remove("correct");
	usleep(6000);
}

void	test_c(void)
{
	int	tests_c;

	tests_c = 0;
	printf(INFO_COLOR "Test for %%c" RESET ":\n");
	for(int i = 0; i < LIMIT_C; i++)
		test_print(&tests_c, WIDTH_C, 3, "%c", i);
	printf("\n\n");
	usleep(1000000);
}

void	test_s(void)
{
}

int	main(void)
{
	test_c();
	test_s();
	return (0);
}
