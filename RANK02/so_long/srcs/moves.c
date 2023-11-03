/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:00:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 11:26:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	right(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x][g->y + 1] == c.wall)
		return ;
	if (g->m[g->x][g->y + 1] == c.exit && g->c == 0)
		exit_game(g);
	g->m[g->x][g->y++] = '0';
	if (g->m[g->x][g->y] == 'C')
		g->c--;
	g->m[g->x][g->y] = 'P';
	g->mv++;
	ft_printf("MOVES: %d\n", g->mv);
	if (g->c == 0)
		g->ext = mlx_xpm_file_to_image(g->mlx, \
			"assets/ext.xpm", &g->i_w, &g->i_h);
	draw(g);
}

void	left(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x][g->y - 1] == c.wall)
		return ;
	if (g->m[g->x][g->y - 1] == c.exit && g->c == 0)
		exit_game(g);
	g->m[g->x][g->y--] = '0';
	if (g->m[g->x][g->y] == 'C')
		g->c--;
	g->m[g->x][g->y] = 'P';
	g->mv++;
	ft_printf("MOVES: %d\n", g->mv);
	if (g->c == 0)
		g->ext = mlx_xpm_file_to_image(g->mlx, \
			"assets/ext.xpm", &g->i_w, &g->i_h);
	draw(g);
}

void	up(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x - 1][g->y] == c.wall)
		return ;
	if (g->m[g->x - 1][g->y] == c.exit && g->c == 0)
		exit_game(g);
	g->m[g->x--][g->y] = '0';
	if (g->m[g->x][g->y] == 'C')
		g->c--;
	g->m[g->x][g->y] = 'P';
	g->mv++;
	ft_printf("MOVES: %d\n", g->mv);
	if (g->c == 0)
		g->ext = mlx_xpm_file_to_image(g->mlx, \
			"assets/ext.xpm", &g->i_w, &g->i_h);
	draw(g);
}

void	down(t_game *g)
{
	t_chars	c;

	c = chars_init();
	if (g->m[g->x + 1][g->y] == c.wall)
		return ;
	if (g->m[g->x + 1][g->y] == c.exit && g->c == 0)
		exit_game(g);
	g->m[g->x++][g->y] = '0';
	if (g->m[g->x][g->y] == 'C')
		g->c--;
	g->m[g->x][g->y] = 'P';
	g->mv++;
	ft_printf("MOVES: %d\n", g->mv);
	if (g->c == 0)
		g->ext = mlx_xpm_file_to_image(g->mlx, \
			"assets/ext.xpm", &g->i_w, &g->i_h);
	draw(g);
}
