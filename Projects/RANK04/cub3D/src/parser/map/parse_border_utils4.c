/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:01:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 09:15:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_1(t_adj *adj, char **map, int i, int j)
{
	if (j == 0)
		return (cub_update_1(adj, map, i, j));
	if (j == (int)ft_strlen(map[i]) - 1)
		return (cub_update_2(adj, map, i, j));
	return (cub_update_3(adj, map, i, j));
}

void	cub_check_2(t_adj *adj, char **map, int i, int j)
{
	if (j == 0)
		return (cub_update_4(adj, map, i, j));
	if (j == (int)ft_strlen(map[i]) - 1)
		return (cub_update_5(adj, map, i, j));
	return (cub_update_6(adj, map, i, j));
}

void	cub_check_3(t_adj *adj, char **map, int i, int j)
{
	if (j == 0)
		return (cub_update_7(adj, map, i, j));
	if (j == (int)ft_strlen(map[i]) - 1)
		return (cub_update_8(adj, map, i, j));
	return (cub_update_9(adj, map, i, j));
}
