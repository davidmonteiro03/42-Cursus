/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:35:04 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 17:40:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_player	cub_get_player_pos(char **map)
{
	t_player	player;
	int			i;
	int			j;

	player = cub_player_init();
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player.x = j * MMAP_SZ + MMAP_SZ / 2;
				player.y = i * MMAP_SZ + MMAP_SZ / 2;
				player.c = map[i][j];
				return (player);
			}
		}
	}
	return (player);
}

void	cub_set_map(t_cub *cub)
{
	char	**tmp;

	tmp = cub_get_lines(cub->config.content, cub->map_info.pos_start, \
		cub->map_info.pos_end);
	cub->map.map = cub_copy(tmp, -1, cub_get_max_len(tmp, ' ', -1));
	multiple_free("%b", tmp);
	cub_little_update(cub->map.map);
	cub_prepare_copy(cub->map.map, -1);
	cub_fix_copy(cub->map.map);
	cub->map.width = (int)cub_get_max_len(cub->map.map, '-', -1);
	cub->map.height = cub_strs_size(cub->map.map);
}
