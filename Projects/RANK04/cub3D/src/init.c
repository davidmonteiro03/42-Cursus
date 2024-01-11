/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:44:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/11 12:41:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	cub_img_init(char *path)
{
	t_img	img;

	img.path = ft_strdup(path);
	img.img = NULL;
	img.bpp = -1;
	img.size_line = -1;
	img.endian = -1;
	img.addr = NULL;
	img.width = -1;
	img.height = -1;
	img.textures = NULL;
	return (img);
}

t_count	cub_count_init(void)
{
	t_count	count;

	count.north = 0;
	count.south = 0;
	count.west = 0;
	count.east = 0;
	count.floor = 0;
	count.ceiling = 0;
	return (count);
}

t_info	cub_info_init(void)
{
	t_info	info;

	info.pos_start = -1;
	info.pos_end = -1;
	return (info);
}

t_file	cub_file_init(void)
{
	t_file	file;

	file.fd = 0;
	file.filename = NULL;
	file.content = NULL;
	return (file);
}

t_cub	*cub_init(void)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	cub->config = cub_file_init();
	cub->map_info = cub_info_init();
	cub->config_info = cub_info_init();
	cub->ceiling = cub_color_init();
	cub->floor = cub_color_init();
	cub->map = cub_map_init();
	cub->keys = cub_keys_init();
	cub->tmp = cub_tmp_init();
	cub->raycast = cub_raycast_init();
	return (cub);
}
