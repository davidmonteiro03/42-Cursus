/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:41:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 15:47:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *g)
{
	mlx_destroy_image(g->mlx, g->col);
	mlx_destroy_image(g->mlx, g->wall);
	mlx_destroy_image(g->mlx, g->bck);
	mlx_destroy_image(g->mlx, g->ext);
	mlx_destroy_image(g->mlx, g->play);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	multiple_free("%b", g->m);
	if (g->exit == 1)
		ft_printf(BCYN "You left the game... WHY???? 😑\n" RESET);
	else
	{
		if (g->c == 0)
			ft_printf(BGRN "You collected everything! 🙂\n" RESET);
		else
			ft_printf(BRED "You didn't collect everything... 🙁\n" RESET);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	move(int k, t_game *g)
{
	if (k == XK_d || k == XK_Right)
		right(g);
	else if (k == XK_a || k == XK_Left)
		left(g);
	else if (k == XK_w || k == XK_Up)
		up(g);
	else if (k == XK_s || k == XK_Down)
		down(g);
	else if (k == XK_Escape)
	{
		g->exit = 1;
		exit_game(g);
	}
	return (0);
}

void	play(t_game *g)
{
	mlx_hook(g->win, KeyPress, KeyPressMask, &move, g);
	mlx_hook(g->win, DestroyNotify, ButtonPressMask, &exit_game, g);
	mlx_loop(g->mlx);
}
