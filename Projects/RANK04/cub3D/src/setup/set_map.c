/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:35:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 15:33:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
