/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:23:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/08 11:14:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_mlx	cub_init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &mlx.screen_width, &mlx.screen_height);
	mlx.screen_size = ft_min(mlx.screen_width, mlx.screen_height) \
		- MARGIN_SIZE;
	mlx.win = mlx_new_window(mlx.mlx, mlx.screen_size, mlx.screen_size, \
		"cub3D");
	return (mlx);
}

void	cub_init_game(t_cub *cub)
{
	cub->img.path = NULL;
	cub->img.textures = NULL;
	cub_get_minimap_size(&cub->map);
	cub_player_position(cub);
	cub_player_angle(&cub->player);
	cub->mlx = cub_init_mlx();
	cub_finish_img(cub->mlx.mlx, &cub->directions.north);
	cub_finish_img(cub->mlx.mlx, &cub->directions.south);
	cub_finish_img(cub->mlx.mlx, &cub->directions.east);
	cub_finish_img(cub->mlx.mlx, &cub->directions.west);
	cub->img.img = mlx_new_image(cub->mlx.mlx, \
		cub->mlx.screen_size, cub->mlx.screen_size);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp, \
		&cub->img.size_line, &cub->img.endian);
}
