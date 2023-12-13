/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:30:20 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:49:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_config_info(t_cub *cub, t_info config_info)
{
	cub_check_config_args(cub, config_info.pos_start, config_info.pos_end);
	cub_check_config_content(cub, config_info.pos_start, config_info.pos_end);
	cub_check_config_duplicates(cub, config_info.pos_start, \
		config_info.pos_end);
	cub_check_config_textures(cub, config_info.pos_start, config_info.pos_end);
}
