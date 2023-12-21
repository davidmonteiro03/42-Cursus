/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 10:15:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	move_player(t_cub *cub, double x, double y)
{
	if (cub->map.map[(int)(cub->player.y + y) / MMAP_SZ] \
		[(int)(cub->player.x + x) / MMAP_SZ] == '1' || \
		cub->map.map[(int)(cub->player.y + y) / MMAP_SZ] \
		[(int)(cub->player.x + x) / MMAP_SZ] == '-')
		return ;
	cub_clear_circle(cub, cub->player.x, cub->player.y, -1);
	auto char *old_c = &cub->map.map[(int)(cub->player.y) / MMAP_SZ] \
		[(int)(cub->player.x) / MMAP_SZ];
	cub->player.x += x;
	cub->player.y += y;
	auto char *new_c = &cub->map.map[(int)(cub->player.y) / MMAP_SZ] \
		[(int)(cub->player.x) / MMAP_SZ];
	if (*old_c != *new_c)
	{
		*new_c = *old_c;
		*old_c = '0';
	}
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

void	cub_update_angle(t_cub *cub, int angle)
{
	cub_clear_circle(cub, cub->player.x, cub->player.y, -1);
	cub->player.angle += angle;
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

int	cub_key_handler(int keycode, t_cub *cub)
{
	if (keycode == XK_Right)
		return (cub_update_angle(cub, 1), 0);
	else if (keycode == XK_Left)
		return (cub_update_angle(cub, -1), 0);
	else if (keycode == XK_w)
		return (move_player(cub, cos(cub->player.angle * M_PI / 180) * \
			STEP, sin(cub->player.angle * M_PI / 180) * STEP), 0);
	else if (keycode == XK_s)
		return (move_player(cub, -cos(cub->player.angle * M_PI / 180) * \
			STEP, -sin(cub->player.angle * M_PI / 180) * STEP), 0);
	else if (keycode == XK_a)
		return (move_player(cub, -cos((cub->player.angle + 90) * \
			M_PI / 180) * STEP, -sin((cub->player.angle + 90) * \
			M_PI / 180) * STEP), 0);
	else if (keycode == XK_d)
		return (move_player(cub, cos((cub->player.angle + 90) * M_PI / 180) * \
			STEP, sin((cub->player.angle + 90) * M_PI / 180) * STEP), 0);
	else if (keycode == XK_Escape)
		cub_exit(cub);
	return (0);
}

int	cub_render(t_cub *cub)
{
	auto int x, y;
	mlx_mouse_get_pos(cub->mlx.mlx, cub->mlx.win, &x, &y);
	if (x < cub->map.width * MMAP_SZ / 2)
		cub->player.angle--;
	else if (x > cub->map.width * MMAP_SZ / 2)
		cub->player.angle++;
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->map.width * MMAP_SZ / 2, \
		cub->map.height * MMAP_SZ / 2);
	return (0);
}
