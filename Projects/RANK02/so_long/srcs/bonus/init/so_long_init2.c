/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:06:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 16:32:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_init_ptrs(t_list **ptrs, t_game game, char c)
{
	int		i;
	int		j;
	t_list	*tmp_node;

	if (ptrs == NULL)
		return ;
	i = -1;
	while (game.map.content[++i] != NULL)
	{
		j = -1;
		while (game.map.content[i][++j] != '\0')
		{
			if (game.map.content[i][j] == c)
			{
				tmp_node = ft_lstnew(&game.map.content[i][j]);
				ft_lstadd_back(ptrs, tmp_node);
			}
		}
	}
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
	player->locked = false;
	if (init == false)
		return ;
	player->pos = so_long_getpos(map.content, PLAYER);
	player->frames = (t_image *)malloc(sizeof(t_image) * PLAYER_FRAMES);
	so_long_init_image(&player->frames[UP], mlx, PATH_PLAYER_UP, true);
	so_long_init_image(&player->frames[LEFT], mlx, PATH_PLAYER_LEFT, true);
	so_long_init_image(&player->frames[DOWN], mlx, PATH_PLAYER_DOWN, true);
	so_long_init_image(&player->frames[RIGHT], mlx, PATH_PLAYER_RIGHT, true);
}

void	so_long_init_frames(t_image **frames, t_mlx mlx, \
	bool init, t_frame info)
{
	char	*buff;

	*frames = NULL;
	if (init == false)
		return ;
	*frames = (t_image *)malloc(sizeof(t_image) * info.size);
	while (info.size-- > 0)
	{
		buff = ft_strdup(info.path);
		buff = ft_joinfree(buff, ft_strdup("frame"));
		buff = ft_joinfree(buff, ft_itoa(info.size));
		buff = ft_joinfree(buff, ft_strdup(".xpm"));
		so_long_init_image(&(*frames)[info.size], mlx, buff, true);
		ft_free((void **)&buff);
	}
}

void	so_long_init_textures(t_textures *textures, t_mlx mlx, bool init)
{
	so_long_init_image(&textures->empty, (t_mlx){0}, NULL, false);
	so_long_init_image(&textures->wall, (t_mlx){0}, NULL, false);
	so_long_init_image(&textures->exit, (t_mlx){0}, NULL, false);
	so_long_init_frames(&textures->collectible, (t_mlx){0}, false, \
		(t_frame){0});
	so_long_init_frames(&textures->enemy_static, (t_mlx){0}, false, \
		(t_frame){0});
	so_long_init_frames(&textures->enemy_moving, (t_mlx){0}, false, \
		(t_frame){0});
	so_long_init_frames(&textures->fireball, (t_mlx){0}, false, \
		(t_frame){0});
	if (init == false)
		return ;
	so_long_init_image(&textures->empty, mlx, PATH_EMPTY, true);
	so_long_init_image(&textures->wall, mlx, PATH_WALL, true);
	so_long_init_image(&textures->exit, mlx, PATH_EXIT, true);
	so_long_init_frames(&textures->collectible, mlx, true, \
		(t_frame){COLLECT_FRAMES, PATH_COLLECT});
	so_long_init_frames(&textures->enemy_static, mlx, true, \
		(t_frame){ENEMY_STATIC_FRAMES, PATH_ENEMY_STATIC});
	so_long_init_frames(&textures->enemy_moving, mlx, true, \
		(t_frame){ENEMY_MOVING_FRAMES, PATH_ENEMY_MOVING});
	so_long_init_frames(&textures->fireball, mlx, true, \
		(t_frame){FIREBALL_FRAMES, PATH_FIREBALL});
}
