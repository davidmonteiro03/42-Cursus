/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:52:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 13:17:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_init(t_game *g)
{
	g->wall = mlx_xpm_file_to_image(g->mlx, \
		g->wall_p, &g->i_w, &g->i_h);
	g->bck = mlx_xpm_file_to_image(g->mlx, \
		g->bck_p, &g->i_w, &g->i_h);
	g->col = mlx_xpm_file_to_image(g->mlx, \
		g->col_p, &g->i_w, &g->i_h);
	g->play = mlx_xpm_file_to_image(g->mlx, \
		g->play_p, &g->i_w, &g->i_h);
	g->ext = mlx_xpm_file_to_image(g->mlx, \
		g->ext_p, &g->i_w, &g->i_h);
}

void	put_image(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	draw(t_game *g)
{
	t_chars	c;
	int		i;
	int		j;

	c = chars_init();
	i = -1;
	while (++i < g->m_h / 32)
	{
		j = -1;
		while (++j < g->m_w / 32)
		{
			if (g->m[i][j] == c.wall)
				put_image(g, g->wall, j * 32, i * 32);
			else if (g->m[i][j] == c.empty)
				put_image(g, g->bck, j * 32, i * 32);
			else if (g->m[i][j] == c.collect)
				put_image(g, g->col, j * 32, i * 32);
			else if (g->m[i][j] == c.start_pos)
				put_image(g, g->play, j * 32, i * 32);
			else if (g->m[i][j] == c.exit)
				put_image(g, g->ext, j * 32, i * 32);
		}
	}
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->m_w, g->m_h, "SO_LONG GAME");
	img_init(g);
	draw(g);
}
