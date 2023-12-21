/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:12:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 10:14:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_circle(t_cub *cub, int x, int y, int i)
{
	while (++i < PLAYER_SZ * 2)
	{
		auto int j = -1;
		while (++j < PLAYER_SZ * 2)
		{
			if ((i - PLAYER_SZ) * (i - PLAYER_SZ) + (j - PLAYER_SZ) * \
				(j - PLAYER_SZ) < PLAYER_SZ * PLAYER_SZ)
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
					PLAYER_SZ + i, y - PLAYER_SZ + j, \
					cub_contrast_color(cub->floor.hex, 0x000000, 0xFFFFFF));
		}
	}
}

void	cub_clear_circle(t_cub *cub, int x, int y, int i)
{
	while (++i < PLAYER_SZ * 2)
	{
		auto int j = -1;
		while (++j < PLAYER_SZ * 2)
		{
			if ((i - PLAYER_SZ) * (i - PLAYER_SZ) + (j - PLAYER_SZ) * \
				(j - PLAYER_SZ) < PLAYER_SZ * PLAYER_SZ)
			{
				auto char c = cub->map.map[(int)((y - PLAYER_SZ + j) / \
					MMAP_SZ)][(int)((x - PLAYER_SZ + i) / MMAP_SZ)];
				if (c == '1')
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, cub->ceiling.hex);
				else if (c == '-')
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, 0x999999);
				else if (c == '0' || c == ' ' || ft_strchr("NSEW", c))
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, cub->floor.hex);
			}
		}
	}
}
