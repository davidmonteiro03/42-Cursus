/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 06:17:19 by dcaetano         ###   ########.fr       */
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
	auto char *old_c = &cub->map.map[(int)(cub->player.y) / MMAP_SZ] \
		[(int)(cub->player.x) / MMAP_SZ];
	cub_clear_circle(cub, cub->player.x, cub->player.y, -1);
	cub->player.x += x;
	cub->player.y += y;
	auto char *new_c = &cub->map.map[(int)(cub->player.y) / MMAP_SZ] \
		[(int)(cub->player.x) / MMAP_SZ];
	if (*old_c != *new_c)
	{
		*new_c = *old_c;
		*old_c = '0';
	}
	cub_check_field_of_view(cub, NULL, true, true);
}

void	cub_update_angle(t_cub *cub, int angle)
{
	auto double old_angle = cub->player.angle;
	cub->player.angle += angle;
	auto double new_angle = cub->player.angle;
	if (old_angle > new_angle)
		return (cub_check_field_of_view(cub, &old_angle, true, false));
	if (old_angle < new_angle)
		return (cub_check_field_of_view(cub, &old_angle, false, true));
	return (cub_check_field_of_view(cub, NULL, false, false));
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

int	mouse_render(t_cub *cub)
{
	auto int x, y;
	mlx_mouse_get_pos(cub->mlx.mlx, cub->mlx.win, &x, &y);
	if (x < cub->map.width * MMAP_SZ / 2)
		return (cub_update_angle(cub, -1), 0);
	else if (x > cub->map.width * MMAP_SZ / 2)
		return (cub_update_angle(cub, 1), 0);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->map.width * MMAP_SZ / 2, \
		cub->map.height * MMAP_SZ / 2);
	return (0);
}
