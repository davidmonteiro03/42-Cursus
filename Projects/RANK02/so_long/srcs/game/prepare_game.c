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

#include "../../includes/so_long.h"

void	prepare_game(t_game *g, t_mapinfo info)
{
	g->size.m_w = info.n_columns * 32;
	g->size.m_h = info.n_lines * 32;
	g->data.c = info.n_collect;
	g->data.x = info.start_x;
	g->data.y = info.start_y;
	g->dir = dir_init();
	g->data.mv = 0;
}
