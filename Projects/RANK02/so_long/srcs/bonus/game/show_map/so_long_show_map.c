/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_show_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:52:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 10:12:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

void	so_long_show_map(t_game *game)
{
	if (game->player.pos.x - game->mlx.win_height / 2 < 0)
		so_long_show_map_case1(game);
	else if (game->player.pos.x + game->mlx.win_height / 2 > \
		game->map.height - 1)
		so_long_show_map_case2(game);
	else
		so_long_show_map_case3(game);
}
