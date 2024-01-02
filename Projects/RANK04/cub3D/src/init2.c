/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:58:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 15:29:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_map	cub_map_init(void)
{
	t_map	map;

	map.map = NULL;
	map.height = 0;
	map.width = 0;
	return (map);
}

t_color	cub_color_init(void)
{
	t_color	color;

	color.blue = -1;
	color.green = -1;
	color.red = -1;
	color.hex = 0;
	return (color);
}

t_mlx	cub_mlx_init(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	return (mlx);
}

t_player	cub_player_init(void)
{
	t_player	player;

	player.x = -1;
	player.y = -1;
	player.c = '0';
	player.angle = -1;
	return (player);
}

t_keys	cub_keys_init(void)
{
	t_keys	keys;

	keys.w = false;
	keys.a = false;
	keys.s = false;
	keys.d = false;
	keys.left = false;
	keys.right = false;
	return (keys);
}
