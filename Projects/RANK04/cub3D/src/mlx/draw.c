/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:26:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 13:26:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_square(t_cub *cub, t_coord coord, int size, int color)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = coord.x - 1;
	while (++tmp_x < size + coord.x)
	{
		tmp_y = coord.y - 1;
		while (++tmp_y < size + coord.y)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, tmp_x, tmp_y, color);
	}
}
