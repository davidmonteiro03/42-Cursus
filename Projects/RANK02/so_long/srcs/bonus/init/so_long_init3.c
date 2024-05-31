/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:01:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 14:08:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	so_long_init_frames(int (*frames)[4])
{
	(*frames)[COL] = 0;
	(*frames)[SEN] = 0;
	(*frames)[MEN] = 0;
	(*frames)[FRB] = 0;
}

void	so_long_init_img_background(t_image *image, t_mlx mlx)
{
	image->width = mlx.win_width * TEXTURE_SIZE;
	image->height = mlx.win_height * TEXTURE_SIZE;
	image->img = mlx_new_image(mlx.mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, \
		&image->size_line, &image->endian);
}

void	so_long_init_time(t_time *time)
{
	time->start = (struct timeval){0, 0};
	time->end = (struct timeval){0, 0};
}

void	so_long_init_sprites(t_sprites *sprites)
{
	so_long_init_time(&sprites->time[FRM]);
	so_long_init_time(&sprites->time[ENE]);
	so_long_init_time(&sprites->time[SPL]);
	so_long_init_frames(&sprites->frames);
}
