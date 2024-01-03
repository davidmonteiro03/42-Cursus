/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:12:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 12:30:39 by dcaetano         ###   ########.fr       */
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
	else if (c == '0' || c == ' ' || c == cub->player.c)
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, 0x666666});
	else if (c == '-')
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, 0x333333});
}

void	cub_update_angle(t_cub *cub, int angle)
{
	cub->player.angle += angle;
	usleep(10000);
}
