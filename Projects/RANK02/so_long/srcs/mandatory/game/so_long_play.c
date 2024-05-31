/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:41:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:18:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	so_long_render(t_game *game)
{
	so_long_show_map(game);
	return (0);
}

void	so_long_play(t_game *game)
{
	so_long_init_mlx(&game->mlx, game->map, true);
	so_long_init_textures(&game->textures, game->mlx, true);
	so_long_init_player(&game->player, game->mlx, game->map, true);
	so_long_find_nearest_collect(game);
	game->exit = so_long_getpos(game->map.content, EXIT);
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, &so_long_keypress, game);
	mlx_hook(game->mlx.win, DestroyNotify, NoEventMask, &so_long_close, game);
	mlx_loop_hook(game->mlx.mlx, &so_long_render, game);
	mlx_loop(game->mlx.mlx);
}
