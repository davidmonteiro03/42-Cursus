/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 19:25:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_mapinfo	info;
	t_game		g;

	if (ac != 2)
		simperror("Try this: ./so_long {arg} [ex: map1.ber]");
	info = mapinfo_init();
	g.m = NULL;
	parse_arg(av[1], &info, &g.m);
	prepare_game(&g, info);
	init_game(&g);
	multiple_free("%b", g.m);
	return (EXIT_SUCCESS);
}
