/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:12:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 08:16:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_player(t_cub *cub, int start, int end)
{
	char	**map;
	int		i;
	int		j;
	int		count;

	count = 0;
	map = cub_get_lines(cub->config.content, start, end);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
				count++;
	}
	multiple_free("%b", map);
	if (count == 0)
		cub_error_file(cub, ERROR_PLAYER_NONE, false);
	if (count > 1)
		cub_error_file(cub, ERROR_PLAYER_MULTIPLE, false);
}
