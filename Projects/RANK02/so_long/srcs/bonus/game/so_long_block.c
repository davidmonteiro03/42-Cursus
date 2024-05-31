/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:20:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 18:05:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_draw_block(t_image *dest, t_image src, t_pos pos, bool transp)
{
	t_pos			tmp_block;
	unsigned int	*tmp_ptr;
	unsigned int	tmp_color;

	tmp_block.x = -1;
	while (++tmp_block.x < src.width)
	{
		tmp_block.y = -1;
		while (++tmp_block.y < src.height)
		{
			tmp_ptr = (unsigned int *)(dest->addr + \
				((tmp_block.x + pos.x * TEXTURE_SIZE) * dest->bpp / 8) + \
				((tmp_block.y + pos.y * TEXTURE_SIZE) * dest->size_line));
			tmp_color = *(unsigned int *)(src.addr + \
				(tmp_block.x * src.bpp / 8) + \
				(tmp_block.y * src.size_line));
			if (ft_istransp(tmp_color) && transp == true)
				continue ;
			*tmp_ptr = tmp_color;
		}
	}
}

void	so_long_put_block(t_game *game, t_image *image, t_pos pos, char *c)
{
	if (*c != WALL)
		so_long_draw_block(image, game->textures.empty, pos, false);
	else
		so_long_draw_block(image, game->textures.wall, pos, false);
	if (c == &game->map.content[game->exit.x][game->exit.y] && \
		game->comp.collectible == 0)
		return (so_long_draw_block(image, game->textures.exit, pos, true));
	if (c == &game->map.content[game->player.pos.x][game->player.pos.y])
		return (so_long_draw_block(image, *game->player.current, pos, true));
	if (*c == COLLECT)
		so_long_draw_block(image, game->textures.collectible \
			[game->sprites.frames[COL] % COLLECT_FRAMES], pos, true);
	else if (*c == STATIC_ENEMY)
		so_long_draw_block(image, game->textures.enemy_static \
			[game->sprites.frames[SEN] % ENEMY_STATIC_FRAMES], pos, true);
	else if (*c == MOVING_ENEMY)
		so_long_draw_block(image, game->textures.enemy_moving \
			[game->sprites.frames[MEN] % ENEMY_MOVING_FRAMES], pos, true);
	else if (*c == FIREBALL)
		so_long_draw_block(image, game->textures.fireball \
			[game->sprites.frames[FRB] % FIREBALL_FRAMES], pos, true);
}
