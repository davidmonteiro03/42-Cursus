/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:15:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 15:05:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_print_message(t_mlx mlx, t_message *message, \
	unsigned int color)
{
	mlx_string_put(mlx.mlx, mlx.win, \
		message->pos.x * TEXTURE_SIZE, message->pos.y * TEXTURE_SIZE, \
		color, message->text);
	ft_free((void **)&message->text);
}

void	so_long_update_info(t_game *game, unsigned int color, bool moves)
{
	t_message	msg;

	if (moves == true)
		game->player.moves++;
	msg.pos = (t_pos){game->mlx.win_width + 1, 1};
	msg.text = ft_joinfree(ft_strdup("Moves: "), ft_itoa(game->player.moves));
	so_long_print_message(game->mlx, &msg, color);
}
