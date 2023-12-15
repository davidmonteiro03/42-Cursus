/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:52:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 08:29:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

t_coord	cub_get_coord(char **strs, int i)
{
	t_coord	coord;
	int		j;

	coord.x = -1;
	coord.y = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (strs[i][j] != '-' && \
				strs[i][j] != '1' && \
				strs[i][j] != 'V')
			{
				coord.x = i;
				coord.y = j;
				return (coord);
			}
		}
	}
	return (coord);
}

void	cub_flood_fill(t_cub *cub, char **map, int x, int y)
{
	char	old;

	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	old = map[x][y];
	map[x][y] = 'V';
	if (old == '-')
		return (multiple_free("%b", map), \
			cub_error_file(cub, ERROR_WALLS, false));
	if (x > 0)
		cub_flood_fill(cub, map, x - 1, y);
	if (x < cub_strs_size(map) - 1)
		cub_flood_fill(cub, map, x + 1, y);
	if (y > 0)
		cub_flood_fill(cub, map, x, y - 1);
	if (y < (int)ft_strlen(map[x]) - 1)
		cub_flood_fill(cub, map, x, y + 1);
}

void	cub_check_border(t_cub *cub, int start, int end)
{
	t_coord	coord;
	char	**map;
	char	**copy;

	map = cub_get_lines(cub->config.content, start, end);
	copy = cub_copy(map, -1, cub_get_max_len(map, -1));
	multiple_free("%b", map);
	cub_little_update(copy);
	cub_prepare_copy(copy, -1);
	coord = cub_get_coord(copy, -1);
	while (coord.x != -1 && coord.y != -1)
	{
		cub_flood_fill(cub, copy, coord.x, coord.y);
		coord = cub_get_coord(copy, -1);
	}
	multiple_free("%b", copy);
}
