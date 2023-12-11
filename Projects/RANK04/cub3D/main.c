/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 20:59:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

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

	ft_printf("======MAPS======\n");
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
			ft_printf("---------%d---------\n", map_info->count);
			cub_display_strs(file_content, j, i - 1);
			continue ;
		}
		i++;
	}
}

void	cub_check_config(char **file_content, int i, t_info *config_info)
{
	int	j;

	ft_printf("======CONFIG======\n");
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
			ft_printf("---------%d---------\n", config_info->count);
			cub_display_strs(file_content, j, i - 1);
			continue ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = cub_init();
	if (!cub)
		return (1);
	cub_check_input(cub, argc, argv);
	cub_check_file_content(cub);
	cub_check_maps(cub->config.content, 0, &cub->map_info);
	cub_check_config(cub->config.content, 0, &cub->config_info);
	printf("map_info->pos: %d\n", cub->map_info.pos);
	printf("config_info->pos: %d\n", cub->config_info.pos);
	cub_exit(cub);
	return (0);
}
