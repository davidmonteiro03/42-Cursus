/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:05:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 15:41:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_mmap_check_a(t_cub *cub)
{
	(void)cub;
	cub_display_strs(cub->map.map, 0, cub_strs_size(cub->map.map) - 1);
}
