/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:26:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 21:38:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

bool	cub_check_char_util(t_adj adj)
{
	return (!((adj.up == '-' || adj.left == '-' || \
		adj.right == '-' || adj.down == '-') && adj.center != '1'));
}

bool	cub_check_char_border(char **map, int i, int j)
{
	t_adj	adj;

	adj = (t_adj){'-', '-', '-', '-', '-'};
	if (i == 0)
		return (cub_check_1(&adj, map, i, j), cub_check_char_util(adj));
	if (i == cub_strs_size(map) - 1)
		return (cub_check_2(&adj, map, i, j), cub_check_char_util(adj));
	return (cub_check_3(&adj, map, i, j), cub_check_char_util(adj));
}

bool	cub_check_walls(char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '-')
				continue ;
			if (!cub_check_char_border(map, i, j))
				return (false);
		}
	}
	return (true);
}

void	cub_check_border_pro(t_cub *cub, int start, int end)
{
	char	**map;
	char	**copy;

	map = cub_get_lines(cub->config.content, start, end);
	copy = cub_copy_2(map, -1, cub_get_max_len(map, ' ', -1));
	multiple_free("%b", map);
	cub_little_update(copy);
	cub_prepare_copy(copy, -1);
	cub_fix_copy(copy);
	if (!cub_check_walls(copy, -1))
	{
		multiple_free("%b", copy);
		cub_error_file(cub, ERROR_WALLS, false);
	}
	multiple_free("%b", copy);
}
