/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:01:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 20:10:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_check_pixel(t_cub *cub, int x, int y, bool erase)
{
	if (!erase)
		return (mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0x00FF00), (void)0);
	auto int pos_x = (int)((cub->player.x + x) / MMAP_SZ);
	auto int pos_y = (int)((cub->player.y + y) / MMAP_SZ);
	if (cub->map.map[pos_y][pos_x] == '1')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0xCCCCCC);
	else if (cub->map.map[pos_y][pos_x] == '0' || \
		cub->map.map[pos_y][pos_x] == ' ' || \
		cub->map.map[pos_y][pos_x] == cub->player.c)
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0x666666);
	else if (cub->map.map[pos_y][pos_x] == '-')
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			cub->tmp.x + x, cub->tmp.y + y, 0x333333);
}

void	cub_draw_player(t_cub *cub, bool erase)
{
	auto int i = PLAYER_SZ * -1 - 1;
	auto int sum = 1;
	while (++i <= PLAYER_SZ)
	{
		auto int j = PLAYER_SZ * -1 - 1;
		while (++j <= PLAYER_SZ)
			if (j >= (sum - 1) * -1 && j <= sum - 1)
				cub_check_pixel(cub, j, i, erase);
		if (i < 0)
			sum++;
		else
			sum--;
	}
}

void	cub_small_check_2(t_cub *cub, char *old_c, char *new_c)
{
	if (*old_c != *new_c)
	{
		*new_c = *old_c;
		*old_c = '0';
		if (cub->map.width >= MINIMAP_SZ && cub->map.height >= MINIMAP_SZ)
			cub_mmap_check(cub, true);
		else
			cub_check_simple_mmap(cub, \
				ft_min(cub->map.width, cub->map.height), true);
	}
	else
	{
		if (cub->map.width >= MINIMAP_SZ && cub->map.height >= MINIMAP_SZ)
			cub_mmap_check(cub, false);
		else
			cub_check_simple_mmap(cub, \
				ft_min(cub->map.width, cub->map.height), false);
	}
	cub_draw_player(cub, false);
}

void	cub_small_check(t_cub *cub, double x, double y)
{
	char	*char_1;
	char	*char_2;

	char_1 = &cub->map.map[(int)((cub->player.y + y) / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	char_2 = &cub->map.map[(int)((cub->player.y) / MMAP_SZ)] \
		[(int)((cub->player.x + x) / MMAP_SZ)];
	auto char *old_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	cub_draw_player(cub, true);
	if (*char_1 != '1' && *char_1 != '-')
		cub->player.y += y;
	if (*char_2 != '1' && *char_2 != '-')
		cub->player.x += x;
	auto char *new_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	cub_small_check_2(cub, old_c, new_c);
}

void	cub_check_keys(t_cub *cub, int x)
{
	if (cub->keys.right || (x > 500 && x < 700))
		cub_update_angle(cub, 1);
	else if (cub->keys.left || (x > 0 && x < 200))
		cub_update_angle(cub, -1);
	if (cub->keys.w)
		cub_move_player(cub, cos(cub->player.angle * M_PI / 180.0) * STEP, \
			sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.s)
		cub_move_player(cub, -cos(cub->player.angle * M_PI / 180.0) * STEP, \
			-sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.a)
		cub_move_player(cub, -cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, -sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
	else if (cub->keys.d)
		cub_move_player(cub, cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
}
