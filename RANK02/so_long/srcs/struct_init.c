/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:36:51 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 13:20:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
