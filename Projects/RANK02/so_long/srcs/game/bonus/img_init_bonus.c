/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:21:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 11:21:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

t_play_i	play_img_init_bonus(t_game *g)
{
	t_play_i	play;

	play.play = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.play.play, \
		&g->size.i_w, &g->size.i_h);
	play.play_r = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.play.play_r, \
		&g->size.i_w, &g->size.i_h);
	play.play_l = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.play.play_l, \
		&g->size.i_w, &g->size.i_h);
	play.play_u = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.play.play_u, \
		&g->size.i_w, &g->size.i_h);
	play.play_d = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.play.play_d, \
		&g->size.i_w, &g->size.i_h);
	return (play);
}

t_std_i	std_img_init_bonus(t_game *g)
{
	t_std_i	std;

	std.bck = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.std.bck, \
		&g->size.i_w, &g->size.i_h);
	std.col = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.std.col, \
		&g->size.i_w, &g->size.i_h);
	std.ext = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.std.ext, \
		&g->size.i_w, &g->size.i_h);
	std.wal = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.std.wal, \
		&g->size.i_w, &g->size.i_h);
	return (std);
}

t_fire_i	fire_img_init_bonus(t_game *g)
{
	t_fire_i	fire;

	fire.fire_1 = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.fire.fire_1, \
		&g->size.i_w, &g->size.i_h);
	fire.fire_2 = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.fire.fire_2, \
		&g->size.i_w, &g->size.i_h);
	fire.fire_3 = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.fire.fire_3, \
		&g->size.i_w, &g->size.i_h);
	fire.fire_4 = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.fire.fire_4, \
		&g->size.i_w, &g->size.i_h);
	fire.fire_5 = mlx_xpm_file_to_image(g->mlx.mlx, g->dir.fire.fire_5, \
		&g->size.i_w, &g->size.i_h);
	return (fire);
}

t_img	img_init_bonus(t_game *g)
{
	t_img	img;

	img.play = play_img_init_bonus(g);
	img.std = std_img_init_bonus(g);
	img.fire = fire_img_init_bonus(g);
	return (img);
}
