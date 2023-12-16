/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 21:54:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_player	cub_get_player_pos(char **map)
{
	t_player	player;
	int			i;
	int			j;

	player = cub_player_init();
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player.x = j;
				player.y = i;
				player.c = map[i][j];
				return (player);
			}
		}
	}
	return (player);
}

void	cub_draw_square(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 32)
	{
		j = -1;
		while (++j < 32)
			mlx_pixel_put(mlx->mlx, mlx->win, x + i, y + j, color);
	}
}

void	cub_draw_map(t_mlx *mlx, char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				cub_draw_square(mlx, j * 32, i * 32, 0xFFFFFF);
			else if (map[i][j] == '0' || map[i][j] == ' ')
				cub_draw_square(mlx, j * 32, i * 32, 0x444444);
			else if (ft_strchr("NSEW", map[i][j]))
			{
				cub_draw_square(mlx, j * 32, i * 32, 0x444444);
				mlx_pixel_put(mlx->mlx, mlx->win, j * 32 + 16, \
					i * 32 + 16, 0xFF0000);
			}
		}
	}
}

void	cub_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, \
		cub->map.width * 32, cub->map.height * 32, "cub3D");
	cub->player = cub_get_player_pos(cub->map.map);
	cub_draw_map(&cub->mlx, cub->map.map, -1);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_key_handler, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_loop(cub->mlx.mlx);
}
