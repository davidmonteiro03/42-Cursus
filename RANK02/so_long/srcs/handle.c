/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 13:40:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int k, t_game *g, t_chars c)
{
	c = chars_init();
	if ((k == XK_Up || k == XK_w) && g->m[g->x - 1][g->y] != c.wall)
		up(g);
	else if ((k == XK_Down || k == XK_s) && g->m[g->x + 1][g->y] != c.wall)
		down(g);
	else if ((k == XK_Left || k == XK_a) && g->m[g->x][g->y - 1] != c.wall)
		left(g);
	else if ((k == XK_Right || k == XK_d) && g->m[g->x][g->y + 1] != c.wall)
		right(g);
	else if (k == XK_Escape)
		mlx_destroy_window(g->mlx, g->win);
	system("clear");
	display_strs(g->m);
	return (0);
}
