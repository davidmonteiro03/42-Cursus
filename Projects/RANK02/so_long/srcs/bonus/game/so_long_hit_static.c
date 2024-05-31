/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hit_static.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:09:26 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 08:22:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	so_long_hit_enemy(t_game *game, t_pos pos)
{
	t_pos	tmp;
	char	c;

	tmp = (t_pos){game->player.pos.x + pos.x, game->player.pos.y + pos.y};
	c = game->map.content[tmp.x][tmp.y];
	if (c == STATIC_ENEMY)
		so_long_kill_enemy(&game->static_enemies, game, tmp);
}

void	so_long_find_collect(t_map *map, t_pos pos, int *possible_collects)
{
	if (map->content[pos.x][pos.y] == WALL || \
		map->content[pos.x][pos.y] == VISIT || \
		map->content[pos.x][pos.y] == STATIC_ENEMY || \
		map->content[pos.x][pos.y] == MOVING_ENEMY)
		return ;
	if (map->content[pos.x][pos.y] == COLLECT)
		(*possible_collects)++;
	map->content[pos.x][pos.y] = VISIT;
	so_long_find_collect(map, (t_pos){pos.x - 1, pos.y}, possible_collects);
	so_long_find_collect(map, (t_pos){pos.x + 1, pos.y}, possible_collects);
	so_long_find_collect(map, (t_pos){pos.x, pos.y - 1}, possible_collects);
	so_long_find_collect(map, (t_pos){pos.x, pos.y + 1}, possible_collects);
}

void	so_long_hit_static(t_game *game)
{
	t_map	tmp;
	int		possible_collects;

	tmp = ft_mapdup(game->map);
	possible_collects = 0;
	so_long_find_collect(&tmp, game->player.pos, &possible_collects);
	ft_freeptrs((void ***)&tmp.content);
	if (possible_collects > 0)
		return ;
	if (game->player.current == &game->player.frames[UP])
		return (so_long_hit_enemy(game, (t_pos){-1, 0}));
	if (game->player.current == &game->player.frames[LEFT])
		return (so_long_hit_enemy(game, (t_pos){0, -1}));
	if (game->player.current == &game->player.frames[DOWN])
		return (so_long_hit_enemy(game, (t_pos){1, 0}));
	return (so_long_hit_enemy(game, (t_pos){0, 1}));
}
