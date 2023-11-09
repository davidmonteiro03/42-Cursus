/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:13:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 11:13:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, img, x, y);
}

void	draw_game(t_game *g)
{
	t_chars	c;
	int		i;
	int		j;

	c = chars_init();
	i = -1;
	while (g->data.m[++i])
	{
		j = -1;
		while (g->data.m[i][++j])
		{
			if (g->data.m[i][j] == c.collect)
				put_image(g, g->img.std.col, j * 32, i * 32);
			else if (g->data.m[i][j] == c.start_pos)
				put_image(g, g->img.play.play, j * 32, i * 32);
			else if (g->data.m[i][j] == c.exit)
				put_image(g, g->img.std.ext, j * 32, i * 32);
			else if (g->data.m[i][j] == c.wall)
				put_image(g, g->img.std.wal, j * 32, i * 32);
			else
				put_image(g, g->img.std.bck, j * 32, i * 32);
		}
	}
}

void	init_game(t_game *g)
{
	g->mlx.mlx = mlx_init();
	g->mlx.win = mlx_new_window(g->mlx.mlx, g->size.m_w, g->size.m_h, \
		"DAVID'S GAME");
	g->img = img_init(g);
	draw_game(g);
}
