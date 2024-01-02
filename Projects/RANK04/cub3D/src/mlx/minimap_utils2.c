/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 18:08:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_4(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MINIMAP_SZ - 2;
	while (++alt_y < MINIMAP_SZ)
	{
		auto int x = -1;
		while (++x < MINIMAP_SZ)
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
		y++;
	}
	cub->tmp.x = cub->player.x;
	cub->tmp.y = cub->player.y;
	while (cub->tmp.x > (MINIMAP * 2 + 1) * MMAP_SZ)
		cub->tmp.x -= MMAP_SZ;
	while (cub->tmp.y > (MINIMAP * 2 + 1) * MMAP_SZ)
		cub->tmp.y -= MMAP_SZ;
	printf("cub->tmp.x: %.lf\n", cub->tmp.x);
	printf("cub->tmp.y: %.lf\n", cub->tmp.y);
}

void	cub_draw_mmap_5(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MINIMAP_SZ - 2;
	while (++alt_y < MINIMAP_SZ)
	{
		auto int alt_x = -1;
		auto int x = cub->map.width - MINIMAP_SZ - 2;
		while (++alt_x < MINIMAP_SZ)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			x++;
		}
		y++;
	}
}

void	cub_draw_mmap_6(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MINIMAP_SZ - 2;
	while (++alt_y < MINIMAP_SZ)
	{
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MINIMAP - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
		}
		y++;
	}
}
