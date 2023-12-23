/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:18:00 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/22 21:18:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	*cub_new_image(void *mlx, t_img *img)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx, img->path, &img->width, &img->height);
	return (image);
}
