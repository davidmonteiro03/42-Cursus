/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hit_moving.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:09:26 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 08:38:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static void	so_long_hit_enemy(t_game *game, int direction)
{
	t_list		*node;
	t_fireball	*fireball;

	fireball = ft_newfireball(game->player.pos, direction);
	node = ft_lstnew(fireball);
	ft_lstadd_back(&game->fireballs, node);
}

void	so_long_hit_moving(t_game *game)
{
	if (game->player.locked == true)
		return ;
	if (game->player.current == &game->player.frames[UP])
		return (so_long_hit_enemy(game, UP));
	if (game->player.current == &game->player.frames[LEFT])
		return (so_long_hit_enemy(game, LEFT));
	if (game->player.current == &game->player.frames[DOWN])
		return (so_long_hit_enemy(game, DOWN));
	return (so_long_hit_enemy(game, RIGHT));
}
