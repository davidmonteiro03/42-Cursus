/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:18:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_tmp	cub_tmp_init(void)
{
	t_tmp	tmp;

	tmp.x = -1;
	tmp.y = -1;
	return (tmp);
}

t_raycast	cub_raycast_init(void)
{
	t_raycast	raycast;

	raycast.camera_x = -1;
	raycast.ray_dir_x = -1;
	raycast.ray_dir_y = -1;
	raycast.map_x = -1;
	raycast.map_y = -1;
	raycast.delta_dist_x = -1;
	raycast.delta_dist_y = -1;
	raycast.hit = -1;
	raycast.step_x = -1;
	raycast.step_y = -1;
	raycast.side_dist_x = -1;
	raycast.side_dist_y = -1;
	raycast.side = -1;
	raycast.perp_wall_dist = -1;
	raycast.line_height = -1;
	raycast.draw_start = -1;
	raycast.draw_end = -1;
	raycast.wall_x = -1;
	return (raycast);
}

void	*cub_new_image(void *mlx, t_img *img)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx, img->path, &img->width, &img->height);
	return (image);
}
