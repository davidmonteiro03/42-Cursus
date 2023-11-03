/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:49:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 15:33:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	prepare_game(t_game *g, t_mapinfo info)
{
	g->m_w = info.n_columns * 32;
	g->m_h = info.n_lines * 32;
	g->c = info.n_collect;
	g->x = info.start_x;
	g->y = info.start_y;
	g->bck_p = "assets/imgs/bck.xpm";
	g->col_p = "assets/imgs/col.xpm";
	g->ext_p = "assets/imgs/ext.xpm";
	g->play_p = "assets/imgs/play.xpm";
	g->wall_p = "assets/imgs/wal.xpm";
	g->play_r_p = "assets/imgs/play_r.xpm";
	g->play_l_p = "assets/imgs/play_l.xpm";
	g->play_u_p = "assets/imgs/play_u.xpm";
	g->play_d_p = "assets/imgs/play_d.xpm";
	g->mv = 0;
	g->exit = 0;
}

t_chars	chars_init(void)
{
	t_chars	chars;

	chars.empty = '0';
	chars.wall = '1';
	chars.collect = 'C';
	chars.exit = 'E';
	chars.start_pos = 'P';
	return (chars);
}

t_mapinfo	mapinfo_init(void)
{
	t_mapinfo	mapinfo;

	mapinfo.n_collect = 0;
	mapinfo.n_exit = 0;
	mapinfo.n_start_pos = 0;
	mapinfo.n_lines = 0;
	mapinfo.n_columns = 0;
	mapinfo.start_x = -1;
	mapinfo.start_y = -1;
	return (mapinfo);
}
