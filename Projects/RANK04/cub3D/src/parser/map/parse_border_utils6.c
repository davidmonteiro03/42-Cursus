/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils6.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:10:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 09:11:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_update_4(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = '-';
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = '-';
}

void	cub_update_5(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = '-';
	adj->down = '-';
}

void	cub_update_6(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = '-';
}
