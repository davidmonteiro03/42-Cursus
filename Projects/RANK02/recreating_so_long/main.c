/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 19:14:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	so_long_usage(void)
{
	ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
	exit(1);
}

void	so_long_check_args(int argc, char **argv)
{
	if (argc != 2)
		so_long_usage();
	if (ft_strlen(argv[1]) < 1)
		so_long_usage();
}

int	main(int argc, char **argv)
{
	so_long_check_args(argc, argv);
	return ((void)argc, (void)argv, 0);
}
