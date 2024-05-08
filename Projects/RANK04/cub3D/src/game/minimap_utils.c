/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:57:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/08 11:09:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_last_column(t_cub *cub, int x, int y)
{
	auto int tmp_y = y * MINIMAP - 1;
	while (++tmp_y < (y + 1) * MINIMAP + STROKE - 1)
	{
		cub_draw_pixel(&cub->img, x * MINIMAP, tmp_y, BORDER_COLOR);
		auto int tmp_i = -1;
		while (++tmp_i < STROKE)
			cub_draw_pixel(&cub->img, x * MINIMAP + tmp_i, \
				tmp_y, BORDER_COLOR);
	}
}

void	cub_draw_last_line(t_cub *cub, int x, int y)
{
	auto int tmp_x = -1;
	while (++tmp_x < x * MINIMAP + STROKE)
	{
		cub_draw_pixel(&cub->img, tmp_x, y * MINIMAP, BORDER_COLOR);
		auto int tmp_i = -1;
		while (++tmp_i < STROKE)
			cub_draw_pixel(&cub->img, tmp_x, \
				y * MINIMAP + tmp_i, BORDER_COLOR);
	}
}

void	cub_small_update(t_cub *cub)
{
	cub->tmp.x += (cub->player.pos_y - (int)cub->player.pos_y) * MINIMAP;
	cub->tmp.y += (cub->player.pos_x - (int)cub->player.pos_x) * MINIMAP;
}
