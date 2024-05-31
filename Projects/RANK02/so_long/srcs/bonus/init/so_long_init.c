/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:55:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 08:06:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_init_file(t_file *file, const char *name)
{
	file->fd = -1;
	file->content = NULL;
	file->name = NULL;
	if (name == NULL)
		return ;
	file->name = ft_strdup(name);
	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return ;
	file->content = ft_readfile(file->fd);
	close(file->fd);
}

void	so_long_init_map(t_map *map, char **content)
{
	map->height = 0;
	map->width = 0;
	map->true_pos[START] = (t_pos){INT_MAX, INT_MAX};
	map->true_pos[END] = (t_pos){INT_MIN, INT_MIN};
	map->content = NULL;
	if (content == NULL)
		return ;
	map->content = content;
	while (map->content[0][map->width])
		map->width++;
	while (map->content[map->height])
		map->height++;
}

void	so_long_init_comp(t_comp *comp, t_comp src)
{
	comp->collectible = src.collectible;
	comp->map_exit = src.map_exit;
	comp->start_position = src.start_position;
	comp->unknown = src.unknown;
}

void	so_long_init_mlx(t_mlx *mlx, t_map map, bool init)
{
	int	tmp_x;
	int	tmp_y;

	mlx->mlx = NULL;
	mlx->win = NULL;
	if (init == true)
	{
		mlx->mlx = mlx_init();
		mlx_get_screen_size(mlx->mlx, &tmp_x, &tmp_y);
		mlx->win_width = map.width;
		mlx->win_height = map.height;
		if ((mlx->win_width + MARGIN + MENU) * TEXTURE_SIZE > tmp_x)
			mlx->win_width = tmp_x / TEXTURE_SIZE - MARGIN - MENU;
		if ((mlx->win_height + MARGIN) * TEXTURE_SIZE > tmp_y)
			mlx->win_height = tmp_y / TEXTURE_SIZE - MARGIN;
		mlx->win = mlx_new_window(mlx->mlx, \
			(mlx->win_width + MENU) * TEXTURE_SIZE, \
			mlx->win_height * TEXTURE_SIZE, \
			GAME_TITLE);
	}
}

void	so_long_init(t_game *game)
{
	so_long_init_file(&game->file, NULL);
	so_long_init_map(&game->map, NULL);
	so_long_init_comp(&game->comp, (t_comp){0});
	so_long_init_mlx(&game->mlx, (t_map){0}, false);
	so_long_init_textures(&game->textures, (t_mlx){0}, false);
	so_long_init_player(&game->player, (t_mlx){0}, (t_map){0}, false);
	so_long_init_sprites(&game->sprites);
	game->static_enemies = NULL;
	game->moving_enemies = NULL;
	game->ptrs_collect = NULL;
	game->fireballs = NULL;
}
