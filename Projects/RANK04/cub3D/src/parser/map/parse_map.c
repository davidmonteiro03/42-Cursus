/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:20:01 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 11:52:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_map_info(t_cub *cub, t_info map_info)
{
	cub_check_multiple_maps(cub, map_info.pos_start, map_info.pos_end);
	cub_check_border(cub, map_info.pos_start, map_info.pos_end);
}
