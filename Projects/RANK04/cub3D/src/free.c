/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:41:44 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 18:23:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_img(void *mlx, t_img img)
{
	if (img.img)
		mlx_destroy_image(mlx, img.img);
	if (img.path)
		free(img.path);
	if (img.textures)
		free(img.textures);
}

void	free_map(t_map map)
{
	if (map.map)
		multiple_free("%b", map.map);
}

void	free_file(t_file file)
{
	if (file.filename)
		free(file.filename);
	if (file.content)
		multiple_free("%b", file.content);
}
