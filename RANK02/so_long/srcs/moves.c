/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:26:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 13:36:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	up(t_game *g)
{
	g->m[g->x--][g->y] = '0';
	if (g->m[g->x][g->y] == 'E')
		end_game(g);
	if (g->m[g->x][g->y] == 'C')
		g->c++;
	g->m[g->x][g->y] = 'P';
}

void	down(t_game *g)
{
	g->m[g->x++][g->y] = '0';
	if (g->m[g->x][g->y] == 'E')
		end_game(g);
	if (g->m[g->x][g->y] == 'C')
		g->c++;
	g->m[g->x][g->y] = 'P';
}

void	left(t_game *g)
{
	g->m[g->x][g->y--] = '0';
	if (g->m[g->x][g->y] == 'E')
		end_game(g);
	if (g->m[g->x][g->y] == 'C')
		g->c++;
	g->m[g->x][g->y] = 'P';
}

void	right(t_game *g)
{
	g->m[g->x][g->y++] = '0';
	if (g->m[g->x][g->y] == 'E')
		end_game(g);
	if (g->m[g->x][g->y] == 'C')
		g->c++;
	g->m[g->x][g->y] = 'P';
}
