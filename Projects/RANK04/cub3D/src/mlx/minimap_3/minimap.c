/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:07:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 19:09:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_small_update_c(t_cub *cub)
{
	cub->tmp.x += (int)cub->player.x % MMAP_SZ;
	cub->tmp.y += (int)cub->player.y % MMAP_SZ;
}

void	cub_mmap_check_c_1(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_3 < 0)
		cub_draw_mmap_c_1(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_3 > cub->map.width - 1)
		cub_draw_mmap_c_2(cub, draw);
	else
		cub_draw_mmap_c_3(cub, draw);
}

void	cub_mmap_check_c_2(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_3 < 0)
		cub_draw_mmap_c_4(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_3 > cub->map.width - 1)
		cub_draw_mmap_c_5(cub, draw);
	else
		cub_draw_mmap_c_6(cub, draw);
}

void	cub_mmap_check_c_3(t_cub *cub, bool draw)
{
	if ((int)(cub->player.x / MMAP_SZ) - MMAP_3 < 0)
		cub_draw_mmap_c_7(cub, draw);
	else if ((int)(cub->player.x / MMAP_SZ) + MMAP_3 > cub->map.width - 1)
		cub_draw_mmap_c_8(cub, draw);
	else
		cub_draw_mmap_c_9(cub, draw);
}

void	cub_mmap_check_c(t_cub *cub, bool draw)
{
	if ((int)(cub->player.y / MMAP_SZ) - MMAP_3 < 0)
		cub_mmap_check_c_1(cub, draw);
	else if ((int)(cub->player.y / MMAP_SZ) + MMAP_3 > cub->map.height - 1)
		cub_mmap_check_c_2(cub, draw);
	else
		cub_mmap_check_c_3(cub, draw);
}
