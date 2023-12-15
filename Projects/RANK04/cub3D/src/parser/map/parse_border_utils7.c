/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils7.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:15:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 09:16:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_update_7(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = '-';
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = map[i + 1][j];
}

void	cub_update_8(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = '-';
	adj->down = map[i + 1][j];
}

void	cub_update_9(t_adj *adj, char **map, int i, int j)
{
	adj->up = map[i - 1][j];
	adj->left = map[i][j - 1];
	adj->center = map[i][j];
	adj->right = map[i][j + 1];
	adj->down = map[i + 1][j];
}
