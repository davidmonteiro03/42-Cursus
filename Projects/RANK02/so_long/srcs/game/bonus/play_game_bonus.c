/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:35:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 11:35:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	move_bonus(int k, t_game *g)
{
	if (k == XK_d || k == XK_Right)
		right_bonus(g);
	if (k == XK_a || k == XK_Left)
		left_bonus(g);
	if (k == XK_w || k == XK_Up)
		up_bonus(g);
	if (k == XK_s || k == XK_Down)
		down_bonus(g);
	else if (k == XK_Escape)
		close_game_bonus(g);
	check_clear_fire_bonus(g);
	return (0);
}

void	put_fire_onmap_bonus(t_game *g, void *img)
{
	int	i;
	int	j;

	i = -1;
	while (g->data.m[++i])
	{
		j = -1;
		while (g->data.m[i][++j])
			if (g->data.m[i][j] == 'F')
				put_image_bonus(g, img, j * 32, i * 32);
	}
}

void	put_black_back(t_game *g)
{
	int	i;
	int	j;

	i = g->size.m_h - 32;
	while (++i < g->size.m_h + 32)
	{
		j = -1;
		while (++j < g->size.m_w)
			mlx_pixel_put(g->mlx.mlx, g->mlx.win, j, i, 0x000000);
	}
}

int	animate_bonus(t_game *g)
{
	static int	frame;

	if (frame % 5 == 0)
		put_fire_onmap_bonus(g, g->img.fire.fire_1);
	else if (frame % 5 == 1)
		put_fire_onmap_bonus(g, g->img.fire.fire_2);
	else if (frame % 5 == 2)
		put_fire_onmap_bonus(g, g->img.fire.fire_3);
	else if (frame % 5 == 3)
		put_fire_onmap_bonus(g, g->img.fire.fire_4);
	else
		put_fire_onmap_bonus(g, g->img.fire.fire_5);
	frame++;
	usleep(55000);
	return (0);
}

void	play_game_bonus(t_game *g)
{
	mlx_hook(g->mlx.win, KeyPress, KeyPressMask, &move_bonus, g);
	mlx_hook(g->mlx.win, DestroyNotify, NoEventMask, &close_game_bonus, g);
	mlx_loop_hook(g->mlx.mlx, &animate_bonus, g);
	mlx_loop(g->mlx.mlx);
}
