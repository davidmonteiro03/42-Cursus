/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_nearest_collect.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:16:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 12:09:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_update_target(t_pos *target, t_player player, \
	t_map *map, double *min_dist)
{
	t_pos	it;
	t_pos	tmp;
	double	ret;

	tmp = (t_pos){0, 0};
	it.x = -1;
	while (map->content[++it.x] != NULL)
	{
		it.y = -1;
		while (map->content[it.x][++it.y] != '\0')
		{
			if (map->content[it.x][it.y] == COLLECT && \
				tmp.x == 0 && tmp.y == 0)
			{
				map->content[it.x][it.y] = EMPTY;
				tmp = it;
			}
		}
	}
	ret = sqrt(pow(tmp.x - player.pos.x, 2) + pow(tmp.y - player.pos.y, 2));
	if (ret < *min_dist)
	{
		*min_dist = ret;
		*target = tmp;
	}
}

void	so_long_find_nearest_collect(t_game *game)
{
	t_map	tmp;
	t_pos	target;
	int		len;
	double	min_dest;
	int		best_frame;

	tmp = ft_mapdup(game->map);
	min_dest = INT_MAX;
	target = (t_pos){0, 0};
	len = -1;
	while (++len < game->comp.collectible)
		so_long_update_target(&target, game->player, &tmp, &min_dest);
	best_frame = so_long_get_best_frame(game->map.content, \
		game->player.pos, target);
	game->player.current = &game->player.frames[best_frame];
	ft_freeptrs((void ***)&tmp.content);
}
