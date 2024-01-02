/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:12:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 18:11:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_shape(t_mlx mlx, int x, int y, t_color color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MMAP_SZ)
	{
		j = -1;
		while (++j < MMAP_SZ)
			mlx_pixel_put(mlx.mlx, mlx.win, \
				x * MMAP_SZ + j, y * MMAP_SZ + i, color.hex);
	}
}

void	cub_check_shape(t_cub *cub, int x, int y, char c)
{
	if (c == '1')
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, 0xCCCCCC});
	else if (c == '0' || c == ' ' || ft_strchr("NSEW", c))
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, 0x666666});
	else if (c == '-')
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, 0x333333});
}

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
					PLAYER_SZ + i, y - PLAYER_SZ + j, 0x00FF00);
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
						PLAYER_SZ + i, y - PLAYER_SZ + j, 0xCCCCCC);
				else if (c == '0' || c == ' ' || ft_strchr("NSEW", c))
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, 0x666666);
				else if (c == '-')
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, 0x333333);
			}
		}
	}
}

void	cub_update_angle(t_cub *cub, int angle)
{
	cub->player.angle += angle;
	usleep(10000);
}
