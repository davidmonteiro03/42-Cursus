/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:55:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/11 12:34:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_finish_img(void *mlx, t_img *img)
{
	img->img = cub_new_image(mlx, img);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
		&img->size_line, &img->endian);
	img->textures = (unsigned int *)malloc(sizeof(unsigned int) * \
		(img->width * img->height));
	auto int x = -1;
	while (++x < img->width)
	{
		auto int y = -1;
		while (++y < img->height)
		{
			auto unsigned int color = *(unsigned int *)(img->addr + \
				(x * img->bpp / 8) + (y * img->size_line));
			img->textures[y * img->width + x] = cub_convert_to_rgb(color);
		}
	}
}
