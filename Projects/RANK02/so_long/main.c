/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/24 07:21:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_mapinfo	info;
	t_game		g;

	if (ac != 2)
		simperror(BCYN "Try this" BWHT ": " RESET \
		"./so_long {arg} [ex: map1.ber]" RESET);
	info = mapinfo_init();
	g.data.m = NULL;
	parse_arg(av[1], &info, &g.data.m);
	prepare_game(&g, info);
	init_game(&g);
	play_game(&g);
	exit_game(&g);
	return (EXIT_SUCCESS);
}
