/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:39:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 11:39:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	clean_play_imgs_bonus(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.play.play);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_r);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_l);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_u);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_d);
}

void	clean_std_imgs_bonus(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.std.bck);
	mlx_destroy_image(g->mlx.mlx, g->img.std.col);
	mlx_destroy_image(g->mlx.mlx, g->img.std.ext);
	mlx_destroy_image(g->mlx.mlx, g->img.std.wal);
}

void	clean_fire_imgs_bonus(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.fire.fire_1);
	mlx_destroy_image(g->mlx.mlx, g->img.fire.fire_2);
	mlx_destroy_image(g->mlx.mlx, g->img.fire.fire_3);
	mlx_destroy_image(g->mlx.mlx, g->img.fire.fire_4);
	mlx_destroy_image(g->mlx.mlx, g->img.fire.fire_5);
}

void	clean_imgs_bonus(t_game *g)
{
	clean_play_imgs_bonus(g);
	clean_std_imgs_bonus(g);
	clean_fire_imgs_bonus(g);
}

int	exit_game_bonus(t_game *g)
{
	clean_imgs_bonus(g);
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
	multiple_free("%b", g->data.m);
	exit(EXIT_SUCCESS);
	return (0);
}
