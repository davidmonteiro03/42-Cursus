/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:12:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_free_file(t_file *file)
{
	if (file == NULL)
		return ;
	ft_freeptrs((void ***)&file->content);
	ft_free((void **)&file->name);
	file->fd = -1;
}

void	so_long_free_mlx(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->mlx != NULL)
	{
		if (mlx->win != NULL)
		{
			mlx_destroy_window(mlx->mlx, mlx->win);
			mlx->win = NULL;
		}
		mlx_destroy_display(mlx->mlx);
	}
	ft_free((void **)&mlx->mlx);
}

void	so_long_free_image(t_image *image, t_mlx mlx)
{
	if (image == NULL || mlx.mlx == NULL)
		return ;
	if (image->img != NULL)
	{
		mlx_destroy_image(mlx.mlx, image->img);
		image->img = NULL;
	}
}

void	so_long_free_textures(t_textures *textures, t_mlx mlx)
{
	if (textures == NULL || mlx.mlx == NULL)
		return ;
	so_long_free_image(&textures->empty, mlx);
	so_long_free_image(&textures->wall, mlx);
	so_long_free_image(&textures->collectible, mlx);
	so_long_free_image(&textures->exit, mlx);
}

void	so_long_free(t_game *game)
{
	if (game == NULL)
		return ;
	so_long_free_textures(&game->textures, game->mlx);
	so_long_free_player(&game->player, game->mlx);
	so_long_free_mlx(&game->mlx);
	so_long_free_file(&game->file);
}
