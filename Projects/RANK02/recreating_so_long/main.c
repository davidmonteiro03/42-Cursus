/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 20:55:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	so_long_check_args(argc, argv);
	so_long_parse_file(argv[1]);
	return ((void)argc, (void)argv, 0);
}
