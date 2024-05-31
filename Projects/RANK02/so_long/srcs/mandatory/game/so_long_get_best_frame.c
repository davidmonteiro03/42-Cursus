/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_best_frame.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:09:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 12:15:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	so_long_best_frame_left(char **map, t_pos player, t_pos target)
{
	if (map[player.x][player.y - 1] != WALL)
		return (LEFT);
	if (target.x - player.x > 0)
		return (DOWN);
	return (UP);
}

int	so_long_best_frame_right(char **map, t_pos player, t_pos target)
{
	if (map[player.x][player.y + 1] != WALL)
		return (RIGHT);
	if (target.x - player.x > 0)
		return (DOWN);
	return (UP);
}

int	so_long_best_frame_up(char **map, t_pos player, t_pos target)
{
	if (map[player.x - 1][player.y] != WALL)
		return (UP);
	if (target.y - player.y > 0)
		return (RIGHT);
	return (LEFT);
}

int	so_long_best_frame_down(char **map, t_pos player, t_pos target)
{
	if (map[player.x + 1][player.y] != WALL)
		return (DOWN);
	if (target.y - player.y > 0)
		return (RIGHT);
	return (LEFT);
}

int	so_long_get_best_frame(char **map, t_pos player, t_pos target)
{
	if (abs(target.x - player.x) < abs(target.y - player.y))
	{
		if (target.y < player.y)
			return (so_long_best_frame_left(map, player, target));
		return (so_long_best_frame_right(map, player, target));
	}
	if (target.x < player.x)
		return (so_long_best_frame_up(map, player, target));
	return (so_long_best_frame_down(map, player, target));
}
