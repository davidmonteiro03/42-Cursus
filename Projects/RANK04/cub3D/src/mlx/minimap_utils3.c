/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 16:24:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_7(t_cub *cub, bool draw, bool print)
{
	auto int alt_y = -1;
	auto int y = (int)(cub->player.y / MMAP_SZ) - MINIMAP - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
	{
		++alt_y;
		auto int x = -1;
		while (++x < MINIMAP_SZ)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
			if (print)
				printf("%c", cub->map.map[y][x]);
		}
		if (print)
			printf("\n");
	}
	cub_small_update(cub);
}

void	cub_draw_mmap_8(t_cub *cub, bool draw, bool print)
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
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
			if (print)
				printf("%c", cub->map.map[y][x]);
			x++;
		}
		if (print)
			printf("\n");
	}
	cub_small_update(cub);
}

void	cub_draw_mmap_9(t_cub *cub, bool draw, bool print)
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
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
			if (print)
				printf("%c", cub->map.map[y][x]);
		}
		if (print)
			printf("\n");
	}
	cub_small_update(cub);
}
