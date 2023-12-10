/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:23:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 13:23:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_color	cub_get_color(char **tmp)
{
	t_color	color;

	color.red = (int)cub_atol(tmp[0]);
	color.green = (int)cub_atol(tmp[1]);
	color.blue = (int)cub_atol(tmp[2]);
	color.color = cub_rgb_to_hex(color.red, color.green, color.blue);
	return (color);
}

t_coord	cub_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}
