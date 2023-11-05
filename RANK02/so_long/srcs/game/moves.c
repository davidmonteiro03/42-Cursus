/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:35:00 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 14:35:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	right(t_game *g)
{
	t_chars	c;

	put_image(g, g->img.play.play_r, g->data.y * 32, g->data.x * 32);
	c = chars_init();
	if (g->data.m[g->data.x][g->data.y + 1] == c.wall)
		return ;
	if (g->data.m[g->data.x][g->data.y + 1] == c.exit && g->data.c == 0)
		exit_game(g);
	if (g->data.m[g->data.x][g->data.y + 1] == c.exit)
		return ;
	if (g->data.m[g->data.x][g->data.y + 1] == c.collect)
		g->data.c--;
	put_image(g, g->img.std.bck, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y++] = c.empty;
	put_image(g, g->img.play.play_r, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y] = c.start_pos;
	g->data.mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BGRN "%d" RESET "\n", g->data.mv);
}

void	left(t_game *g)
{
	t_chars	c;

	put_image(g, g->img.play.play_l, g->data.y * 32, g->data.x * 32);
	c = chars_init();
	if (g->data.m[g->data.x][g->data.y - 1] == c.wall)
		return ;
	if (g->data.m[g->data.x][g->data.y - 1] == c.exit && g->data.c == 0)
		exit_game(g);
	if (g->data.m[g->data.x][g->data.y - 1] == c.exit)
		return ;
	if (g->data.m[g->data.x][g->data.y - 1] == c.collect)
		g->data.c--;
	put_image(g, g->img.std.bck, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y--] = c.empty;
	put_image(g, g->img.play.play_l, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y] = c.start_pos;
	g->data.mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BGRN "%d" RESET "\n", g->data.mv);
}

void	up(t_game *g)
{
	t_chars	c;

	put_image(g, g->img.play.play_u, g->data.y * 32, g->data.x * 32);
	c = chars_init();
	if (g->data.m[g->data.x - 1][g->data.y] == c.wall)
		return ;
	if (g->data.m[g->data.x - 1][g->data.y] == c.exit && g->data.c == 0)
		exit_game(g);
	if (g->data.m[g->data.x - 1][g->data.y] == c.exit)
		return ;
	if (g->data.m[g->data.x - 1][g->data.y] == c.collect)
		g->data.c--;
	put_image(g, g->img.std.bck, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x--][g->data.y] = c.empty;
	put_image(g, g->img.play.play_u, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y] = c.start_pos;
	g->data.mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BGRN "%d" RESET "\n", g->data.mv);
}

void	down(t_game *g)
{
	t_chars	c;

	put_image(g, g->img.play.play_d, g->data.y * 32, g->data.x * 32);
	c = chars_init();
	if (g->data.m[g->data.x + 1][g->data.y] == c.wall)
		return ;
	if (g->data.m[g->data.x + 1][g->data.y] == c.exit && g->data.c == 0)
		exit_game(g);
	if (g->data.m[g->data.x + 1][g->data.y] == c.exit)
		return ;
	if (g->data.m[g->data.x + 1][g->data.y] == c.collect)
		g->data.c--;
	put_image(g, g->img.std.bck, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x++][g->data.y] = c.empty;
	put_image(g, g->img.play.play_d, g->data.y * 32, g->data.x * 32);
	g->data.m[g->data.x][g->data.y] = c.start_pos;
	g->data.mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BGRN "%d" RESET "\n", g->data.mv);
}
