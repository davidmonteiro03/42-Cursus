/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:44:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:05:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
	cub->map_info = cub_info_init();
	cub->config_info = cub_info_init();
	return (cub);
}
