/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 15:26:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_player_move(t_cub *cub, int x, int y)
{
	if (cub->map.map[(int)(cub->player.y + y) / \
		32][(int)(cub->player.x + x) / 32] != '1')
	{
		cub->player.x += x;
		cub->player.y += y;
		return (cub_draw_map(cub, cub->map.map, -1), cub_draw_view(cub));
	}
}

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
	/* else if (keycode == XK_w)
		return (cub_player_move(cub, cos(cub->player.angle * M_PI / 180) * 5, \
			sin(cub->player.angle * M_PI / 180) * 2), 0);
	else if (keycode == XK_s)
		return (cub_player_move(cub, -cos(cub->player.angle * M_PI / 180) * 5, \
			-sin(cub->player.angle * M_PI / 180) * 2), 0);
	else if (keycode == XK_a)
		return (cub_player_move(cub, -cos((cub->player.angle + 90) * M_PI / \
			180) * 5, -sin((cub->player.angle + 90) * M_PI / 180) * 2), 0);
	else if (keycode == XK_d)
		return (cub_player_move(cub, cos((cub->player.angle + 90) * M_PI / \
			180) * 5, sin((cub->player.angle + 90) * M_PI / 180) * 2), 0); */
	else if (keycode == XK_Escape)
		cub_exit(cub);
	return (0);
}
