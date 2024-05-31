/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateposition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:53:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/09 08:23:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	ft_generateutil2(int coord, int player_coord, int range, int start)
{
	if (player_coord == coord + (range / 2))
		return (rand() % range + start);
	coord = rand() % (range / 2) + start;
	if (player_coord < start + (range / 2))
		coord += range / 2;
	return (coord);
}

t_pos	ft_generateutil(t_map map, t_pos player)
{
	t_pos	ret;
	t_pos	range;

	ret.x = map.true_pos[START].x;
	ret.y = map.true_pos[START].y;
	range.x = map.true_pos[END].x - map.true_pos[START].x + 1;
	range.y = map.true_pos[END].y - map.true_pos[START].y + 1;
	if (range.x > 1)
		ret.x = ft_generateutil2(ret.x, player.x, \
			range.x, map.true_pos[START].x);
	if (range.y > 1)
		ret.y = ft_generateutil2(ret.y, player.y, \
			range.y, map.true_pos[START].y);
	return (ret);
}

t_pos	ft_generateposition2(t_map map, t_pos player)
{
	t_pos	tmp;

	tmp = ft_generateutil(map, player);
	while ((map.content[tmp.x][tmp.y] != EMPTY && \
		map.content[tmp.x][tmp.y] != COLLECT) || \
		(tmp.x == player.x && tmp.y == player.y))
		tmp = ft_generateutil(map, player);
	return (tmp);
}

t_pos	ft_generateposition(void)
{
	t_pos	ret;

	ret.x = rand() % 3 - 1;
	ret.y = rand() % 3 - 1;
	while ((ret.x == 0 && ret.y == 0) || \
		(ret.x != 0 && ret.y != 0))
	{
		ret.x = rand() % 3 - 1;
		ret.y = rand() % 3 - 1;
	}
	return (ret);
}
