/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:46:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:15:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_check_mapline(char *line, char *charset, int i)
{
	if (!line || cub_dif_char_in(line, " \t"))
		return (2);
	while (line[++i])
	{
		if (ft_strchr("\t ", line[i]))
			continue ;
		if (!ft_strchr(charset, line[i]))
			return (0);
	}
	return (1);
}

void	cub_check_config(char **file_content, int i, t_info *config_info)
{
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], MAP_CHARSET, -1) == 0)
		{
			if (config_info->pos_start == -1)
				config_info->pos_start = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], MAP_CHARSET, -1) != 2 && \
				cub_check_mapline(file_content[i], MAP_CHARSET, -1) != 1)
				i++;
			config_info->pos_end = i - 1;
			continue ;
		}
		i++;
	}
}

void	cub_check_mixes(t_cub *cub, int start, int end, bool flag)
{
	while (start <= end)
		if (cub_check_mapline(cub->config.content[start++], MAP_CHARSET, -1) \
			== flag)
			cub_error_file(cub, ERROR_FILE, false);
}

void	cub_check_maps(char **file_content, int i, t_info *map_info)
{
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], MAP_CHARSET, -1) == 1)
		{
			if (map_info->pos_start == -1)
				map_info->pos_start = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], MAP_CHARSET, -1) != 2 && \
				cub_check_mapline(file_content[i], MAP_CHARSET, -1) != 0)
				i++;
			map_info->pos_end = i - 1;
			continue ;
		}
		i++;
	}
}

void	cub_check_data(t_cub *cub)
{
	cub_check_config(cub->config.content, 0, &cub->config_info);
	cub_check_maps(cub->config.content, 0, &cub->map_info);
	if (cub->config_info.pos_start == -1)
		cub_error_file(cub, ERROR_FILE, false);
	if (cub->map_info.pos_start == -1)
		cub_error_file(cub, ERROR_FILE, false);
	if (cub->config_info.pos_start > cub->map_info.pos_start)
		cub_error_file(cub, ERROR_FILE, false);
	cub_check_mixes(cub, cub->config_info.pos_start, cub->config_info.pos_end, \
		true);
	cub_check_mixes(cub, cub->map_info.pos_start, cub->map_info.pos_end, \
		false);
	cub_check_config_info(cub, cub->config_info);
}
