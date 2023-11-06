/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:42:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 10:42:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	prepare_game_bonus(t_game *g, t_mapinfo info)
{
	g->size.m_w = info.n_columns * 32;
	g->size.m_h = (info.n_lines + 1) * 32;
	g->data.c = info.n_collect;
	g->data.sc = info.n_collect;
	g->data.x = info.start_x;
	g->data.y = info.start_y;
	g->dir = dir_init_bonus();
	g->data.mv = 0;
}
