/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:07:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 15:31:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_small_update(t_cub *cub)
{
	cub->tmp.x += (int)cub->player.x % MMAP_SZ;
	cub->tmp.y += (int)cub->player.y % MMAP_SZ;
}

void	cub_mmap_check_1(t_cub *cub, bool draw, bool print)
{
	if ((int)(cub->player.x / MMAP_SZ) - MINIMAP < 0)
		cub_draw_mmap_1(cub, draw, print);
	else if ((int)(cub->player.x / MMAP_SZ) + MINIMAP > cub->map.width - 1)
		cub_draw_mmap_2(cub, draw, print);
	else
		cub_draw_mmap_3(cub, draw, print);
}

void	cub_mmap_check_2(t_cub *cub, bool draw, bool print)
{
	if ((int)(cub->player.x / MMAP_SZ) - MINIMAP < 0)
		cub_draw_mmap_4(cub, draw, print);
	else if ((int)(cub->player.x / MMAP_SZ) + MINIMAP > cub->map.width - 1)
		cub_draw_mmap_5(cub, draw, print);
	else
		cub_draw_mmap_6(cub, draw, print);
}

void	cub_mmap_check_3(t_cub *cub, bool draw, bool print)
{
	if ((int)(cub->player.x / MMAP_SZ) - MINIMAP < 0)
		cub_draw_mmap_7(cub, draw, print);
	else if ((int)(cub->player.x / MMAP_SZ) + MINIMAP > cub->map.width - 1)
		cub_draw_mmap_8(cub, draw, print);
	else
		cub_draw_mmap_9(cub, draw, print);
}

void	cub_mmap_check(t_cub *cub, bool draw, bool print)
{
	if ((int)(cub->player.y / MMAP_SZ) - MINIMAP < 0)
		cub_mmap_check_1(cub, draw, print);
	else if ((int)(cub->player.y / MMAP_SZ) + MINIMAP > cub->map.height - 1)
		cub_mmap_check_2(cub, draw, print);
	else
		cub_mmap_check_3(cub, draw, print);
}
