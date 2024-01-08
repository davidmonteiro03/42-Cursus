/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:25:26 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 20:48:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_get_minimap_size(t_map *map)
{
	map->minimap_size = (int)(ft_min(map->width, map->height) - 1) / 2;
	if (map->minimap_size > MINIMAP_SZ)
		map->minimap_size = MINIMAP_SZ;
}

void	cub_player_position(t_cub *cub)
{
	auto int i = -1;
	while (++i < cub->map.height)
	{
		auto int j = -1;
		while (++j < cub->map.width)
		{
			if (ft_strchr(PLAYER_CHARSET, cub->map.map[i][j]))
			{
				cub->player.pos_x = i + 0.5;
				cub->player.pos_y = j + 0.5;
				cub->player.c = cub->map.map[i][j];
				return ;
			}
		}
	}
}

void	cub_player_angle(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	if (player->c == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (player->c == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (player->c == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	player->plane_x = player->dir_y * 0.66;
	player->plane_y = -player->dir_x * 0.66;
}
