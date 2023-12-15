/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:04:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 09:06:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_update_1(t_adj *adj, char **map, int i, int j)
{
	adj->up = '-';
	adj->left = '-';
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = map[i + 1][j];
}

void	cub_update_2(t_adj *adj, char **map, int i, int j)
{
	adj->up = '-';
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = '-';
	adj->down = map[i + 1][j];
}

void	cub_update_3(t_adj *adj, char **map, int i, int j)
{
	adj->up = '-';
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = map[i + 1][j];
}
