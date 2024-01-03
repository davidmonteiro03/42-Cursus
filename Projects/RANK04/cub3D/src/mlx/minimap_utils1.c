/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 16:24:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_1(t_cub *cub, bool draw, bool print)
{
	auto int y = -1;
	while (++y < MINIMAP_SZ)
	{
		auto int x = -1;
		while (++x < MINIMAP_SZ)
		{
			if (draw)
				cub_check_shape(cub, x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
			}
			if (print)
				printf("%c", cub->map.map[y][x]);
		}
		if (print)
			printf("\n");
	}
	cub_small_update(cub);
}

void	cub_draw_mmap_2(t_cub *cub, bool draw, bool print)
{
	auto int y = -1;
	while (++y < MINIMAP_SZ)
	{
		auto int x = cub->map.width - MINIMAP_SZ - 2;
		auto int alt_x = -1;
		while (++alt_x < MINIMAP_SZ)
		{
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
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

void	cub_draw_mmap_3(t_cub *cub, bool draw, bool print)
{
	auto int y = -1;
	while (++y < MINIMAP_SZ)
	{
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MINIMAP - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MINIMAP + MINIMAP_SZ)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
			}
			if (print)
				printf("%c", cub->map.map[y][x]);
		}
		if (print)
			printf("\n");
	}
	cub_small_update(cub);
}
