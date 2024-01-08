/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:17:15 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 20:20:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_check_pixel(t_cub *cub, int x, int y, bool erase)
{
	auto int pos_x = (int)floor((cub->player.pos_x * MINIMAP + y) / MINIMAP);
	auto int pos_y = (int)floor((cub->player.pos_y * MINIMAP + x) / MINIMAP);
	auto char c = cub->map.map[pos_x][pos_y];
	if (!erase)
	{
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, PLAYER_COLOR);
		return ;
	}
	if (c == '1')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, WALL_COLOR);
	else if (c == '-')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, EMPTY_COLOR);
	else
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, FLOOR_COLOR);
}

void	cub_draw_player(t_cub *cub, bool erase)
{
	auto int i = PLAYER_SZ * -1 - 1;
	auto int sum = 1;
	while (++i <= PLAYER_SZ)
	{
		auto int j = PLAYER_SZ * -1 - 1;
		while (++j <= PLAYER_SZ)
			if (j >= (sum - 1) * -1 && j <= sum - 1)
				cub_check_pixel(cub, j, i, erase);
		if (i < 0)
			sum++;
		else
			sum--;
	}
}

void	cub_draw_square(t_cub *cub, int x, int y, unsigned int color)
{
	auto int i = -1;
	while (++i < MINIMAP)
	{
		auto int j = -1;
		while (++j < MINIMAP)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x + i, y + j, color);
	}
}

void	cub_check_shape(t_cub *cub, int x, int y, char c)
{
	if (c == '1')
		cub_draw_square(cub, x * MINIMAP, y * MINIMAP, WALL_COLOR);
	else if (c == '-')
		cub_draw_square(cub, x * MINIMAP, y * MINIMAP, EMPTY_COLOR);
	else
		cub_draw_square(cub, x * MINIMAP, y * MINIMAP, FLOOR_COLOR);
}
