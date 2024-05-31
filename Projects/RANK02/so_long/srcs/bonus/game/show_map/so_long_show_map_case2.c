/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_show_map_case2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:45:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 17:47:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

static void	so_long_show_map_case_a(t_game *game)
{
	t_pos	tmp;
	t_pos	alt;
	t_image	image;

	so_long_init_img_background(&image, game->mlx);
	alt.y = -1;
	tmp.y = game->map.height - game->mlx.win_height - 1;
	while (++alt.y < game->mlx.win_height)
	{
		++tmp.y;
		tmp.x = -1;
		while (++tmp.x < game->mlx.win_width)
			so_long_put_block(game, &image, \
				(t_pos){tmp.x, alt.y}, \
				&game->map.content[tmp.y][tmp.x]);
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, image.img, 0, 0);
	so_long_free_image(&image, game->mlx);
}

static void	so_long_show_map_case_b(t_game *game)
{
	t_pos	tmp;
	t_pos	alt;
	t_image	image;

	so_long_init_img_background(&image, game->mlx);
	alt.y = -1;
	tmp.y = game->map.height - game->mlx.win_height - 1;
	while (++alt.y < game->mlx.win_height)
	{
		++tmp.y;
		alt.x = -1;
		tmp.x = game->map.width - game->mlx.win_width - 1;
		while (++alt.x < game->mlx.win_width)
		{
			++tmp.x;
			so_long_put_block(game, &image, \
				(t_pos){alt.x, alt.y}, \
				&game->map.content[tmp.y][tmp.x]);
		}
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, image.img, 0, 0);
	so_long_free_image(&image, game->mlx);
}

static void	so_long_show_map_case_c(t_game *game)
{
	t_pos	tmp;
	t_pos	alt;
	t_image	image;

	so_long_init_img_background(&image, game->mlx);
	alt.y = -1;
	tmp.y = game->map.height - game->mlx.win_height - 1;
	while (++alt.y < game->mlx.win_height)
	{
		++tmp.y;
		alt.x = -1;
		tmp.x = game->player.pos.y - game->mlx.win_width / 2 - 1;
		while (++tmp.x < game->player.pos.y - \
			game->mlx.win_width / 2 + game->mlx.win_width)
		{
			++alt.x;
			so_long_put_block(game, &image, \
				(t_pos){alt.x, alt.y}, \
				&game->map.content[tmp.y][tmp.x]);
		}
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, image.img, 0, 0);
	so_long_free_image(&image, game->mlx);
}

void	so_long_show_map_case2(t_game *game)
{
	if (game->player.pos.y - game->mlx.win_width / 2 < 0)
		so_long_show_map_case_a(game);
	else if (game->player.pos.y + game->mlx.win_width / 2 > \
		game->map.width - 1)
		so_long_show_map_case_b(game);
	else
		so_long_show_map_case_c(game);
}
