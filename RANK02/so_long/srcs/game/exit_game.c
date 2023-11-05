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

#include "../../includes/so_long.h"

void	clean_play_imgs(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.play.play);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_r);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_l);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_u);
	mlx_destroy_image(g->mlx.mlx, g->img.play.play_d);
}

void	clean_std_imgs(t_game *g)
{
	mlx_destroy_image(g->mlx.mlx, g->img.std.bck);
	mlx_destroy_image(g->mlx.mlx, g->img.std.col);
	mlx_destroy_image(g->mlx.mlx, g->img.std.ext);
	mlx_destroy_image(g->mlx.mlx, g->img.std.wal);
}

void	clean_imgs(t_game *g)
{
	clean_play_imgs(g);
	clean_std_imgs(g);
}

int	exit_game(t_game *g)
{
	clean_imgs(g);
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
	multiple_free("%b", g->data.m);
	exit(EXIT_SUCCESS);
	return (0);
}
