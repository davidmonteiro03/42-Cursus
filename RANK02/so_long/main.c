/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 13:29:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_mapinfo	mapinfo;
	t_game		g;
	char		**map;

	if (ac != 2)
		simperror("Try this: ./so_long {arg} [ex: map1.ber]");
	mapinfo = mapinfo_init();
	map = NULL;
	parse_arg(av[1], &mapinfo, &map);
	prep_game(&g, map, mapinfo);
	multiple_free("%b", map);
	start_game(&g);
	multiple_free("%b", g.m);
	return (EXIT_SUCCESS);
}
