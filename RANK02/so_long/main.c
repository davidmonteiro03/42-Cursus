/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 19:05:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	start_game(void)
{
	void	*mlx;

	mlx = mlx_init();
}

int	main(int ac, char **av)
{
	t_mapinfo	mapinfo;
	char		**map;

	if (ac != 2)
		simperror("Try this: ./so_long {arg} [ex: map1.ber]");
	mapinfo = mapinfo_init();
	map = NULL;
	parse_arg(av[1], &mapinfo, &map);
	start_game();
	multiple_free("%b", map);
	return (EXIT_SUCCESS);
}
