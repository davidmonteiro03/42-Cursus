/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 16:15:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	start_game(t_game *game, t_mapinfo mapinfo, char **map)
{
	int	i;
	int	j;

	game->map = (char **)malloc(sizeof(char *) * (mapinfo.n_lines + 1));
	i = -1;
	while (++i < mapinfo.n_lines)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (mapinfo.n_columns + 1));
		j = -1;
		while (++j < mapinfo.n_columns)
			game->map[i][j] = map[i][j];
		game->map[i][j] = '\0';
	}
	game->map[i] = NULL;
	game->c = 0;
	game->total_c = mapinfo.n_collect;
	game->x = mapinfo.start_x;
	game->y = mapinfo.start_y;
}

void	update_game(t_game *g, char *k)
{
	size_t	t;

	t = ft_strlen(k);
	if (ft_strncmp(k, "W\n", t) == 0 && g->map[g->x - 1][g->y] != '1')
		g->map[g->x--][g->y] = '0';
	else if (ft_strncmp(k, "A\n", t) == 0 && g->map[g->x][g->y - 1] != '1')
		g->map[g->x][g->y--] = '0';
	else if (ft_strncmp(k, "S\n", t) == 0 && g->map[g->x + 1][g->y] != '1')
		g->map[g->x++][g->y] = '0';
	else if (ft_strncmp(k, "D\n", t) == 0 && g->map[g->x][g->y + 1] != '1')
		g->map[g->x][g->y++] = '0';
	if (g->map[g->x][g->y] == 'C')
		g->c++;
	if (ft_strnstr("W\nA\nS\nD\n", k, ft_strlen("W\nA\nS\nD\n")))
		g->map[g->x][g->y] = 'P';
	multiple_free("%a", k);
	if (g->map[g->x][g->y] == 'E')
	{
		display_game(g);
		multiple_free("%b", g->map);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	t_mapinfo	mapinfo;
	t_game		g;
	char		**map;
	char		*k;

	if (ac != 2)
		simperror("Try this: ./so_long {arg} [ex: map1.ber]");
	mapinfo = mapinfo_init();
	map = NULL;
	parse_arg(av[1], &mapinfo, &map);
	start_game(&g, mapinfo, map);
	multiple_free("%b", map);
	system("clear");
	display_game(&g);
	k = get_next_line(0);
	while (k)
	{
		system("clear");
		update_game(&g, k);
		display_game(&g);
		k = get_next_line(0);
	}
	multiple_free("%b", g.map);
	return (EXIT_SUCCESS);
}
