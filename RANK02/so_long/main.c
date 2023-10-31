/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 13:14:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	start_game(t_game *game, t_mapinfo mapinfo)
{
	game->collect = 0;
	game->player_x = mapinfo.start_x;
	game->player_y = mapinfo.start_y;
}

int	main(int ac, char **av)
{
	t_mapinfo	mapinfo;
	t_game		game;

	if (ac != 2)
		simperror("Error\nTry this: ./so_long {arg} [ex: map1.ber]");
	mapinfo = mapinfo_init();
	parse_arg(av[1], &mapinfo);
	start_game(&game, mapinfo);
	ft_printf("x: %d | y: %d\n", game.player_x, game.player_y);
	return (EXIT_SUCCESS);
}
