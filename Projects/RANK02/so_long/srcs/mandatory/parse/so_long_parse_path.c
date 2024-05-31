/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:39:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/05 19:24:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

t_pos	so_long_getpos(char **map, char c)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
			if (map[i][j] == c)
				return ((t_pos){i, j});
	}
	return ((t_pos){0, 0});
}

void	so_long_visit_map(t_map map, t_pos pos, int *rest, bool *end)
{
	if (map.content[pos.x][pos.y] == WALL || \
		map.content[pos.x][pos.y] == VISIT)
		return ;
	if (pos.x < 0)
		return ;
	if (pos.x >= map.height)
		return ;
	if (pos.y < 0)
		return ;
	if (pos.y >= map.width)
		return ;
	if (map.content[pos.x][pos.y] == COLLECT)
		(*rest)--;
	if (map.content[pos.x][pos.y] == EXIT)
		*end = true;
	map.content[pos.x][pos.y] = VISIT;
	so_long_visit_map(map, (t_pos){pos.x - 1, pos.y}, rest, end);
	so_long_visit_map(map, (t_pos){pos.x + 1, pos.y}, rest, end);
	so_long_visit_map(map, (t_pos){pos.x, pos.y - 1}, rest, end);
	so_long_visit_map(map, (t_pos){pos.x, pos.y + 1}, rest, end);
}

void	so_long_parse_path(t_game *game)
{
	t_map	tmp;
	t_pos	pos;
	int		tmp_col;
	bool	finished;

	tmp = ft_mapdup(game->map);
	pos = so_long_getpos(tmp.content, 'P');
	tmp_col = game->comp.collectible;
	finished = false;
	so_long_visit_map(tmp, pos, &tmp_col, &finished);
	ft_freeptrs((void ***)&tmp.content);
	if (tmp_col > 0)
		return (so_long_exit(game, ERROR_FINISH_COLLECT, true, false));
	if (finished == false)
		return (so_long_exit(game, ERROR_FINISH_GAME, true, false));
}
