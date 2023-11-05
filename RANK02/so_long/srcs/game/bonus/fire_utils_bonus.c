/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 19:05:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	put_fire_pos_bonus(t_game *g, int pos, int i, int j)
{
	if (pos == 0)
		g->data.m[i - 1][j - 1] = 'F';
	else if (pos == 1)
		g->data.m[i - 1][j] = 'F';
	else if (pos == 2)
		g->data.m[i - 1][j + 1] = 'F';
	else if (pos == 3)
		g->data.m[i][j - 1] = 'F';
	else if (pos == 4)
		g->data.m[i][j + 1] = 'F';
	else if (pos == 5)
		g->data.m[i + 1][j - 1] = 'F';
	else if (pos == 6)
		g->data.m[i + 1][j] = 'F';
	else if (pos == 7)
		g->data.m[i + 1][j + 1] = 'F';
}
