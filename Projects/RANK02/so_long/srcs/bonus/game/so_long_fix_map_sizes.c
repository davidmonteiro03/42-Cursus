/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_fix_map_sizes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:58:23 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/08 10:17:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_fix_map_sizes(t_map *map)
{
	t_pos	it;

	it.x = -1;
	while (map->content[++it.x] != NULL)
	{
		it.y = -1;
		while (map->content[it.x][++it.y] != '\0')
		{
			if (map->content[it.x][it.y] != WALL && \
				map->content[it.x][it.y] != VISIT)
			{
				if (it.x < map->true_pos[START].x)
					map->true_pos[START].x = it.x;
				if (it.y < map->true_pos[START].y)
					map->true_pos[START].y = it.y;
				if (it.x > map->true_pos[END].x)
					map->true_pos[END].x = it.x;
				if (it.y > map->true_pos[END].y)
					map->true_pos[END].y = it.y;
			}
		}
	}
}
