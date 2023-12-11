/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:46:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 21:49:06 by dcaetano         ###   ########.fr       */
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
	int	j;

	printf("======MAPS======\n");
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 1)
		{
			j = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 2)
				i++;
			map_info->pos = i;
			map_info->count++;
			printf("---------%d---------\n", map_info->count);
			cub_display_strs(file_content, j, i - 1);
			continue ;
		}
		i++;
	}
}

void	cub_check_config(char **file_content, int i, t_info *config_info)
{
	int	j;

	printf("======CONFIG======\n");
	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 0)
		{
			j = i;
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 1)
				i++;
			config_info->pos = i;
			config_info->count++;
			printf("---------%d---------\n", config_info->count);
			cub_display_strs(file_content, j, i - 1);
			continue ;
		}
		i++;
	}
}
