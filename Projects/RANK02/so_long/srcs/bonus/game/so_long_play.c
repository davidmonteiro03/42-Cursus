/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:41:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/08 10:15:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_execute(t_game *game, int pos, int speed, \
	void (*execute)(t_game *))
{
	if (game->sprites.elapsed_time[pos] >= 1.0 / speed)
	{
		execute(game);
		gettimeofday(&game->sprites.time[pos].start, NULL);
	}
}

int	so_long_render(t_game *game)
{
	so_long_update_times(game);
	so_long_execute(game, SPL, SPELL_SPEED, &so_long_move_fireballs);
	so_long_execute(game, ENE, ENEMY_SPEED, &so_long_move_enemies);
	so_long_check_frames(game);
	so_long_show_map(game);
	return (0);
}

void	so_long_fill_map(t_map *map, t_pos pos)
{
	if (map->content[pos.x][pos.y] == WALL || \
		map->content[pos.x][pos.y] == VISIT)
		return ;
	if (pos.x < 0)
		return ;
	if (pos.x < 0)
		return ;
	if (pos.x >= map->height)
		return ;
	if (pos.y < 0)
		return ;
	if (pos.y >= map->width)
		return ;
	map->content[pos.x][pos.y] = VISIT;
	so_long_fill_map(map, (t_pos){pos.x - 1, pos.y});
	so_long_fill_map(map, (t_pos){pos.x + 1, pos.y});
	so_long_fill_map(map, (t_pos){pos.x, pos.y - 1});
	so_long_fill_map(map, (t_pos){pos.x, pos.y + 1});
}

void	so_long_fix_map(t_map *map, t_map tmp)
{
	t_pos	it;

	it.x = -1;
	while (map->content[++it.x] != NULL)
	{
		it.y = -1;
		while (map->content[it.x][++it.y] != '\0')
			if (tmp.content[it.x][it.y] == EMPTY)
				map->content[it.x][it.y] = VISIT;
	}
}

void	so_long_play(t_game *game)
{
	t_map	tmp;

	so_long_init_mlx(&game->mlx, game->map, true);
	so_long_init_textures(&game->textures, game->mlx, true);
	so_long_init_player(&game->player, game->mlx, game->map, true);
	so_long_find_nearest_collect(game);
	so_long_init_ptrs(&game->ptrs_collect, *game, COLLECT);
	tmp = ft_mapdup(game->map);
	so_long_fill_map(&tmp, game->player.pos);
	so_long_fix_map(&game->map, tmp);
	ft_freeptrs((void ***)&tmp.content);
	so_long_fix_map_sizes(&game->map);
	game->exit = so_long_getpos(game->map.content, EXIT);
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, &so_long_keypress, game);
	mlx_hook(game->mlx.win, DestroyNotify, NoEventMask, &so_long_close, game);
	mlx_loop_hook(game->mlx.mlx, &so_long_render, game);
	mlx_loop(game->mlx.mlx);
}
