/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 18:01:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_7(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = (int)(cub->player.y / MMAP_SZ) - MINIMAP - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
	{
		++alt_y;
		auto int x = -1;
		while (++x < MINIMAP_SZ)
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
	}
	cub->tmp.x = (int)(cub->player.x) % ((MINIMAP * 2 + 1) * MMAP_SZ);
	cub->tmp.y = (int)(cub->player.y) % ((MINIMAP * 2 + 1) * MMAP_SZ);
}

void	cub_draw_mmap_8(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = (int)(cub->player.y / MMAP_SZ) - MINIMAP - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
	{
		++alt_y;
		auto int x = cub->map.width - MINIMAP_SZ - 2;
		auto int alt_x = -1;
		while (++alt_x < MINIMAP_SZ)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			x++;
		}
	}
}

void	cub_draw_mmap_9(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = (int)(cub->player.y / MMAP_SZ) - MINIMAP - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
	{
		++alt_y;
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MINIMAP - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
		}
	}
}
