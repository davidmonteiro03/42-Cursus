/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:30:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 08:46:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_move_player(t_game *game, t_pos pos, t_image *new_frame)
{
	t_pos	tmp[3];
	char	*block[3];

	tmp[OLD] = game->player.pos;
	tmp[NEW] = (t_pos){tmp[OLD].x + pos.x, tmp[OLD].y + pos.y};
	tmp[EXT] = game->exit;
	block[OLD] = &game->map.content[tmp[OLD].x][tmp[OLD].y];
	block[NEW] = &game->map.content[tmp[NEW].x][tmp[NEW].y];
	block[EXT] = &game->map.content[tmp[EXT].x][tmp[EXT].y];
	game->player.current = new_frame;
	if (*block[NEW] == WALL || game->player.locked == true)
		return ;
	if (block[NEW] == block[EXT] && game->comp.collectible == 0)
		so_long_close(game);
	if (*block[NEW] == STATIC_ENEMY || *block[NEW] == MOVING_ENEMY)
		so_long_lose(game, *block[NEW]);
	*block[OLD] = EMPTY;
	game->player.pos = tmp[NEW];
	if (ft_ptrinptrs(game->ptrs_collect, block[NEW]))
		so_long_born_enemies(game, block[NEW]);
	if (block[OLD] == block[EXT])
		*block[OLD] = EXIT;
	*block[NEW] = PLAYER;
	so_long_update_info(game, 0x00000000, false);
	so_long_update_info(game, 0x00FFFFFF, true);
}

int	so_long_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		so_long_close(game);
	else if (keycode == XK_w || keycode == XK_Up)
		so_long_move_player(game, (t_pos){-1, 0}, &game->player.frames[UP]);
	else if (keycode == XK_a || keycode == XK_Left)
		so_long_move_player(game, (t_pos){0, -1}, &game->player.frames[LEFT]);
	else if (keycode == XK_s || keycode == XK_Down)
		so_long_move_player(game, (t_pos){1, 0}, &game->player.frames[DOWN]);
	else if (keycode == XK_d || keycode == XK_Right)
		so_long_move_player(game, (t_pos){0, 1}, &game->player.frames[RIGHT]);
	else if (keycode == XK_space)
		so_long_hit_moving(game);
	else if (keycode == XK_Tab)
		so_long_hit_static(game);
	else if (keycode == XK_l)
		game->player.locked = !game->player.locked;
	return (0);
}
