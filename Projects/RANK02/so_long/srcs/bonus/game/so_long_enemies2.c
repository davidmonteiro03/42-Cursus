/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemies2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:31:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 17:35:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_move_enemy(t_game *game, t_enemy *enemy, t_pos new)
{
	t_pos	tmp[2];
	char	*block[4];

	tmp[OLD] = enemy->pos;
	tmp[NEW] = (t_pos){enemy->pos.x + new.x, enemy->pos.y + new.y};
	block[OLD] = &game->map.content[tmp[OLD].x][tmp[OLD].y];
	block[NEW] = &game->map.content[tmp[NEW].x][tmp[NEW].y];
	block[EXT] = &game->map.content[game->exit.x][game->exit.y];
	block[PLAY] = &game->map.content[game->player.pos.x][game->player.pos.y];
	if (*block[NEW] == WALL || *block[NEW] == STATIC_ENEMY || \
		*block[NEW] == MOVING_ENEMY)
		return ;
	if (*block[NEW] == PLAYER)
		so_long_lose(game, MOVING_ENEMY);
	if (*block[NEW] == FIREBALL)
		return (so_long_clear_spell(game, tmp[NEW], block[NEW]), \
			so_long_kill_enemy(&game->moving_enemies, game, tmp[OLD]));
	*block[OLD] = EMPTY;
	if (block[OLD] == block[EXT])
		*block[OLD] = EXIT;
	else if (ft_ptrinptrs(game->ptrs_collect, block[OLD]) == true)
		*block[OLD] = COLLECT;
	*block[NEW] = MOVING_ENEMY;
	enemy->pos = tmp[NEW];
}

void	so_long_move_enemies(t_game *game)
{
	t_list		*tmp;
	t_pos		movpos;
	t_enemy		*enemy;
	int			size[2];

	if (game->moving_enemies == NULL)
		return ;
	tmp = game->moving_enemies;
	while (tmp != NULL)
	{
		enemy = (t_enemy *)tmp->content;
		movpos = ft_generateposition();
		size[START] = ft_lstsize(game->moving_enemies);
		so_long_move_enemy(game, enemy, movpos);
		size[END] = ft_lstsize(game->moving_enemies);
		if (size[START] != size[END])
			tmp = game->moving_enemies;
		else
			tmp = tmp->next;
	}
}
