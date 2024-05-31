/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:20:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 11:54:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

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

void	so_long_put_block(t_game *game, t_image *image, t_pos pos, char c)
{
	if (c != WALL)
		so_long_draw_block(image, game->textures.empty, pos, false);
	else
		so_long_draw_block(image, game->textures.wall, pos, false);
	if (c == COLLECT)
		so_long_draw_block(image, game->textures.collectible, pos, true);
	else if (c == EXIT && game->comp.collectible == 0)
		so_long_draw_block(image, game->textures.exit, pos, true);
	else if (c == PLAYER)
		so_long_draw_block(image, *game->player.current, pos, true);
}
