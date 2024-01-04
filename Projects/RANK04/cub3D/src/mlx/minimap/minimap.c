/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:07:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 23:49:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_small_update(t_cub *cub)
{
	cub->tmp.x += (int)cub->player.x % MMAP_SZ;
	cub->tmp.y += (int)cub->player.y % MMAP_SZ;
}

void	cub_mmap_check_1(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - cub->map.minimap < 0)
		cub_draw_mmap_1(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + \
		cub->map.minimap > cub->map.width - 1)
		cub_draw_mmap_2(cub, draw);
	else
		cub_draw_mmap_3(cub, draw);
}

void	cub_mmap_check_2(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - cub->map.minimap < 0)
		cub_draw_mmap_4(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + \
		cub->map.minimap > cub->map.width - 1)
		cub_draw_mmap_5(cub, draw);
	else
		cub_draw_mmap_6(cub, draw);
}

void	cub_mmap_check_3(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - cub->map.minimap < 0)
		cub_draw_mmap_7(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + \
		cub->map.minimap > cub->map.width - 1)
		cub_draw_mmap_8(cub, draw);
	else
		cub_draw_mmap_9(cub, draw);
}

void	cub_mmap_check(t_cub *cub, bool draw)
{
	if ((int)(cub->player.y / MMAP_SZ) - cub->map.minimap < 0)
		cub_mmap_check_1(cub, draw);
	else if ((int)(cub->player.y / MMAP_SZ) + \
		cub->map.minimap > cub->map.height - 1)
		cub_mmap_check_2(cub, draw);
	else
		cub_mmap_check_3(cub, draw);
}
