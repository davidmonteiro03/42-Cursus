/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:46:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 22:17:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_check_mapline(char *line, char *charset, int i)
{
	if (!line || !*line)
		return (2);
	while (line[++i])
		if (!ft_strchr(charset, line[i]))
			return (0);
	return (1);
}

void	cub_check_maps(char **file_content, int i, t_info *map_info)
{
	printf("======MAPS======\n");
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 1)
		{
			map_info->pos_start = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 2)
				i++;
			map_info->pos_end = i - 1;
			map_info->count++;
			printf("---------%d---------\n", map_info->count);
			cub_display_strs(file_content, map_info->pos_start, \
				map_info->pos_end);
			continue ;
		}
		i++;
	}
}

void	cub_check_config(char **file_content, int i, t_info *config_info)
{
	printf("======CONFIG======\n");
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 0)
		{
			config_info->pos_start = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 1 && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 2)
				i++;
			config_info->pos_end = i - 1;
			cub_display_strs(file_content, config_info->pos_start, \
				config_info->pos_end);
			continue ;
		}
		i++;
	}
}
