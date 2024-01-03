/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:07:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 18:47:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_small_update_a(t_cub *cub)
{
	cub->tmp.x += (int)cub->player.x % MMAP_SZ;
	cub->tmp.y += (int)cub->player.y % MMAP_SZ;
}

void	cub_mmap_check_a_1(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_1 < 0)
		cub_draw_mmap_a_1(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_1 > cub->map.width - 1)
		cub_draw_mmap_a_2(cub, draw);
	else
		cub_draw_mmap_a_3(cub, draw);
}

void	cub_mmap_check_a_2(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_1 < 0)
		cub_draw_mmap_a_4(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_1 > cub->map.width - 1)
		cub_draw_mmap_a_5(cub, draw);
	else
		cub_draw_mmap_a_6(cub, draw);
}

void	cub_mmap_check_a_3(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_1 < 0)
		cub_draw_mmap_a_7(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_1 > cub->map.width - 1)
		cub_draw_mmap_a_8(cub, draw);
	else
		cub_draw_mmap_a_9(cub, draw);
}

void	cub_mmap_check_a(t_cub *cub, bool draw)
{
	if ((int)(cub->player.y / MMAP_SZ) - MMAP_1 < 0)
		cub_mmap_check_a_1(cub, draw);
	else if ((int)(cub->player.y / MMAP_SZ) + MMAP_1 > cub->map.height - 1)
		cub_mmap_check_a_2(cub, draw);
	else
		cub_mmap_check_a_3(cub, draw);
}
