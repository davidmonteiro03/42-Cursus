/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_fireballs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:27:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 17:45:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_clear_spell(t_game *game, t_pos pos, char *block)
{
	t_list	*target;
	char	*exit;
	char	*player;

	target = ft_findnodeposfb(game->fireballs, pos);
	ft_removenode(&game->fireballs, target, free);
	exit = &game->map.content[game->exit.x][game->exit.y];
	player = &game->map.content[game->player.pos.x][game->player.pos.y];
	*block = EMPTY;
	if (block == exit)
		*block = EXIT;
	else if (block == player)
		*block = PLAYER;
	else if (ft_ptrinptrs(game->ptrs_collect, block) == true)
		*block = COLLECT;
}

void	so_long_move_fireball(t_game *game, t_fireball *fireball, t_pos new)
{
	t_pos	tmp[4];
	char	*block[4];

	tmp[OLD] = fireball->pos;
	tmp[NEW] = (t_pos){fireball->pos.x + new.x, fireball->pos.y + new.y};
	tmp[EXT] = game->exit;
	tmp[PLAY] = game->player.pos;
	block[OLD] = &game->map.content[tmp[OLD].x][tmp[OLD].y];
	block[NEW] = &game->map.content[tmp[NEW].x][tmp[NEW].y];
	block[EXT] = &game->map.content[tmp[EXT].x][tmp[EXT].y];
	block[PLAY] = &game->map.content[tmp[PLAY].x][tmp[PLAY].y];
	if (*block[NEW] == WALL || *block[NEW] == STATIC_ENEMY)
		return (so_long_clear_spell(game, tmp[OLD], block[OLD]));
	if (*block[NEW] == MOVING_ENEMY)
		return (so_long_clear_spell(game, tmp[OLD], block[OLD]), \
			so_long_kill_enemy(&game->moving_enemies, game, tmp[NEW]));
	*block[OLD] = EMPTY;
	if (block[OLD] == block[EXT])
		*block[OLD] = EXIT;
	else if (block[OLD] == block[PLAY])
		*block[OLD] = PLAYER;
	else if (ft_ptrinptrs(game->ptrs_collect, block[OLD]) == true)
		*block[OLD] = COLLECT;
	*block[NEW] = FIREBALL;
	fireball->pos = tmp[NEW];
}

void	so_long_move_fireballs(t_game *game)
{
	t_list		*tmp;
	t_fireball	*fireball;
	int			size[2];

	if (game->fireballs == NULL)
		return ;
	tmp = game->fireballs;
	while (tmp != NULL)
	{
		fireball = (t_fireball *)tmp->content;
		size[START] = ft_lstsize(game->fireballs);
		if (fireball->direction == UP)
			so_long_move_fireball(game, fireball, (t_pos){-1, 0});
		else if (fireball->direction == LEFT)
			so_long_move_fireball(game, fireball, (t_pos){0, -1});
		else if (fireball->direction == DOWN)
			so_long_move_fireball(game, fireball, (t_pos){1, 0});
		else
			so_long_move_fireball(game, fireball, (t_pos){0, 1});
		size[END] = ft_lstsize(game->fireballs);
		if (size[START] != size[END])
			tmp = game->fireballs;
		else
			tmp = tmp->next;
	}
}
