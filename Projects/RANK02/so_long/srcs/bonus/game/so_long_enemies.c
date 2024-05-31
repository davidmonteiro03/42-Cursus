/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:53:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 07:57:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_born_enemy(t_list **enemies, t_map *map, \
	char type, t_pos player)
{
	t_list	*node;
	t_enemy	*enemy;
	t_pos	pos;

	pos = ft_generateposition2(*map, player);
	enemy = ft_newenemy(pos);
	node = ft_lstnew(enemy);
	ft_lstadd_back(enemies, node);
	map->content[pos.x][pos.y] = type;
}

void	so_long_kill_enemies(t_list **enemies, t_map *map, t_game game)
{
	t_list	*tmp;
	t_enemy	*temp;

	tmp = *enemies;
	while (tmp != NULL)
	{
		temp = (t_enemy *)tmp->content;
		map->content[temp->pos.x][temp->pos.y] = EMPTY;
		if (ft_ptrinptrs(game.ptrs_collect, \
			&map->content[temp->pos.x][temp->pos.y]) == true)
			map->content[temp->pos.x][temp->pos.y] = COLLECT;
		if (&map->content[temp->pos.x][temp->pos.y] == \
			&map->content[game.exit.x][game.exit.y])
			map->content[temp->pos.x][temp->pos.y] = EXIT;
		tmp = tmp->next;
	}
	ft_lstclear(enemies, free);
	*enemies = NULL;
}

void	so_long_kill_enemy(t_list **enemies, t_game *game, t_pos pos)
{
	t_list	*target;

	game->map.content[pos.x][pos.y] = EMPTY;
	if (ft_ptrinptrs(game->ptrs_collect, \
		&game->map.content[pos.x][pos.y]) == true)
		game->map.content[pos.x][pos.y] = COLLECT;
	if (&game->map.content[pos.x][pos.y] == \
		&game->map.content[game->exit.x][game->exit.y])
		game->map.content[pos.x][pos.y] = EXIT;
	target = ft_findnodepos(*enemies, pos);
	ft_removenode(enemies, target, free);
}

void	so_long_born_enemies(t_game *game, char *ptr)
{
	t_list	*target;

	target = ft_findnodeptr(game->ptrs_collect, ptr);
	game->comp.collectible--;
	ft_removenode(&game->ptrs_collect, target, NULL);
	if (game->comp.collectible == 0)
		game->map.content[game->exit.x][game->exit.y] = EXIT;
	if (ft_lstsize(game->static_enemies) == 3)
	{
		so_long_kill_enemies(&game->static_enemies, &game->map, *game);
		so_long_born_enemy(&game->moving_enemies, &game->map, MOVING_ENEMY, \
			game->player.pos);
	}
	else
		so_long_born_enemy(&game->static_enemies, &game->map, STATIC_ENEMY, \
			game->player.pos);
}
