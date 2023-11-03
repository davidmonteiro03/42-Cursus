/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:00:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 12:51:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	right(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x][g->y + 1] == c.wall)
		return ;
	if (g->m[g->x][g->y + 1] == c.exit)
		exit_game(g);
	if (g->m[g->x][g->y + 1] == c.collect)
		g->c--;
	g->m[g->x][g->y++] = c.empty;
	g->m[g->x][g->y] = c.start_pos;
	g->mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BYLW "%d\n" RESET, g->mv);
	draw(g);
}

void	left(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x][g->y - 1] == c.wall)
		return ;
	if (g->m[g->x][g->y - 1] == c.exit)
		exit_game(g);
	if (g->m[g->x][g->y - 1] == c.collect)
		g->c--;
	g->m[g->x][g->y--] = c.empty;
	g->m[g->x][g->y] = c.start_pos;
	g->mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BYLW "%d\n" RESET, g->mv);
	draw(g);
}

void	up(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x - 1][g->y] == c.wall)
		return ;
	if (g->m[g->x - 1][g->y] == c.exit)
		exit_game(g);
	if (g->m[g->x - 1][g->y] == c.collect)
		g->c--;
	g->m[g->x--][g->y] = c.empty;
	g->m[g->x][g->y] = c.start_pos;
	g->mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BYLW "%d\n" RESET, g->mv);
	draw(g);
}

void	down(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x + 1][g->y] == c.wall)
		return ;
	if (g->m[g->x + 1][g->y] == c.exit)
		exit_game(g);
	if (g->m[g->x + 1][g->y] == c.collect)
		g->c--;
	g->m[g->x++][g->y] = c.empty;
	g->m[g->x][g->y] = c.start_pos;
	g->mv++;
	ft_printf(BCYN "MOVES" BWHT ": " BYLW "%d\n" RESET, g->mv);
	draw(g);
}
