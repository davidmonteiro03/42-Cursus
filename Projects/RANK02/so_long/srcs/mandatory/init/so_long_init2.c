/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:06:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 11:56:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_init_img_background(t_image *image, t_mlx mlx)
{
	image->width = mlx.win_width * TEXTURE_SIZE;
	image->height = mlx.win_height * TEXTURE_SIZE;
	image->img = mlx_new_image(mlx.mlx, image->width, image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, \
		&image->size_line, &image->endian);
}

void	so_long_init_image(t_image *image, t_mlx mlx, \
	char *filename, bool init)
{
	image->img = NULL;
	image->bpp = 0;
	image->endian = 0;
	if (filename == NULL || init == false)
		return ;
	image->img = mlx_xpm_file_to_image(mlx.mlx, filename, \
		&image->width, &image->height);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, \
		&image->size_line, &image->endian);
}

void	so_long_init_player(t_player *player, t_mlx mlx, t_map map, bool init)
{
	player->pos = (t_pos){0, 0};
	player->frames = NULL;
	player->current = NULL;
	player->moves = 0;
	if (init == false)
		return ;
	player->pos = so_long_getpos(map.content, PLAYER);
	player->frames = (t_image *)malloc(sizeof(t_image) * PLAYER_FRAMES);
	so_long_init_image(&player->frames[UP], mlx, PLAYER_UP, true);
	so_long_init_image(&player->frames[LEFT], mlx, PLAYER_LEFT, true);
	so_long_init_image(&player->frames[DOWN], mlx, PLAYER_DOWN, true);
	so_long_init_image(&player->frames[RIGHT], mlx, PLAYER_RIGHT, true);
}

void	so_long_init_textures(t_textures *textures, t_mlx mlx, bool init)
{
	so_long_init_image(&textures->empty, (t_mlx){0}, NULL, false);
	so_long_init_image(&textures->wall, (t_mlx){0}, NULL, false);
	so_long_init_image(&textures->collectible, (t_mlx){0}, NULL, false);
	so_long_init_image(&textures->exit, (t_mlx){0}, NULL, false);
	if (init == false)
		return ;
	so_long_init_image(&textures->empty, mlx, PATH_EMPTY, true);
	so_long_init_image(&textures->wall, mlx, PATH_WALL, true);
	so_long_init_image(&textures->collectible, mlx, PATH_COLLECT, true);
	so_long_init_image(&textures->exit, mlx, PATH_EXIT, true);
}
