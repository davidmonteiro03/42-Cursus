/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:52:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 19:49:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	img_init(t_game *g)
{
	g->bck = mlx_xpm_file_to_image(g->mlx, \
		"assets/wall.xpm", &g->i_w, &g->i_h);
	g->wall = mlx_xpm_file_to_image(g->mlx, \
		"assets/wall.xpm", &g->i_w, &g->i_h);
	g->play = mlx_xpm_file_to_image(g->mlx, \
		"assets/wall.xpm", &g->i_w, &g->i_h);
	g->col = mlx_xpm_file_to_image(g->mlx, \
		"assets/wall.xpm", &g->i_w, &g->i_h);
	g->ext = mlx_xpm_file_to_image(g->mlx, \
		"assets/wall.xpm", &g->i_w, &g->i_h);
}

void	prepare_game(t_game *g, t_mapinfo info)
{
	g->m_w = info.n_columns * 32;
	g->m_h = info.n_lines * 32;
	g->c = info.n_collect;
	g->x = info.start_x;
	g->y = info.start_y;
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->m_w, g->m_h, "SO_LONG GAME");
	g->mv = 0;
	g->end = 0;
	img_init(g);
}
