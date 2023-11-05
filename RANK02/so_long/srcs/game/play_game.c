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

#include "../../includes/so_long.h"

int	move(int k, t_game *g)
{
	if (k == XK_d || k == XK_Right)
		right(g);
	if (k == XK_a || k == XK_Left)
		left(g);
	if (k == XK_w || k == XK_Up)
		up(g);
	if (k == XK_s || k == XK_Down)
		down(g);
	else if (k == XK_Escape)
		exit_game(g);
	return (0);
}

void	play_game(t_game *g)
{
	mlx_hook(g->mlx.win, KeyPress, KeyPressMask, &move, g);
	mlx_hook(g->mlx.win, DestroyNotify, NoEventMask, &exit_game, g);
	mlx_loop(g->mlx.mlx);
}
