/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 13:24:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_map	prepare_map(void)
{
	t_map	map;

	map.empty = '0';
	map.wall = '1';
	map.collect = 'C';
	map.exit = 'E';
	map.start_pos = 'P';
	return (map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_putendl_fd(av[ac - 1], 1);
		exit(EXIT_FAILURE);
	}
	map = prepare_map();
	ft_printf("empty: %c\nwall: %c\ncollect: %c\nexit: %c\nstart_pos: %c\n", \
		map.empty, map.wall, map.collect, map.exit, map.start_pos \
	);
	return (EXIT_SUCCESS);
}
