/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:28:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/03 12:35:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	do_op(int a, char *op, int b)
{
	if (*op == '+')
		printf("%d", a + b);
	else if (*op == '-')
		printf("%d", a - b);
	else if (*op == '*')
		printf("%d", a * b);
	else if (*op == '/')
		printf("%d", a / b);
	else if (*op == '%')
		printf("%d", a % b);
	else
		printf("0");
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(atoi(argv[1]), argv[2], atoi(argv[3]));
	printf("\n");
	return (0);
}
