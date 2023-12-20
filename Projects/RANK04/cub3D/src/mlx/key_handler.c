/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 19:48:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_key_handler(int keycode, t_cub *cub)
{
	if (keycode == XK_Right)
	{
		cub->player.angle++;
		return (cub_draw_map(cub, cub->map.map, -1), cub_draw_view(cub), 0);
	}
	else if (keycode == XK_Left)
	{
		cub->player.angle--;
		return (cub_draw_map(cub, cub->map.map, -1), cub_draw_view(cub), 0);
	}
	else if (keycode == XK_Escape)
		cub_exit(cub);
	return (0);
}

int	mouse_render(t_cub *cub)
{
	auto int x, y;
	mlx_mouse_get_pos(cub->mlx.mlx, cub->mlx.win, &x, &y);
	if (x < cub->map.width * MMAP_SZ / 2)
	{
		cub->player.angle--;
		cub_draw_map(cub, cub->map.map, -1);
		cub_draw_view(cub);
	}
	else if (x > cub->map.width * MMAP_SZ / 2)
	{
		cub->player.angle++;
		cub_draw_map(cub, cub->map.map, -1);
		cub_draw_view(cub);
	}
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->map.width * MMAP_SZ / 2, \
		cub->map.height * MMAP_SZ / 2);
	return (0);
}
