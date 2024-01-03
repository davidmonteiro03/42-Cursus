/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 18:35:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_draw_mmap_a_4(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_1 - 2;
	while (++alt_y < MMAP_SZ_1)
	{
		auto int x = -1;
		while (++x < MMAP_SZ_1)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		y++;
	}
	cub_small_update_a(cub);
}

void	cub_draw_mmap_a_5(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_1 - 2;
	while (++alt_y < MMAP_SZ_1)
	{
		auto int alt_x = -1;
		auto int x = cub->map.width - MMAP_SZ_1 - 2;
		while (++alt_x < MMAP_SZ_1)
		{
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
			x++;
		}
		y++;
	}
	cub_small_update_a(cub);
}

void	cub_draw_mmap_a_6(t_cub *cub, bool draw)
{
	auto int alt_y = -1;
	auto int y = cub->map.height - MMAP_SZ_1 - 2;
	while (++alt_y < MMAP_SZ_1)
	{
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MMAP_1 - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MMAP_1 + MMAP_SZ_1)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		y++;
	}
	cub_small_update_a(cub);
}
