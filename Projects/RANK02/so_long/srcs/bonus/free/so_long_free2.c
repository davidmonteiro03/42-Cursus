/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:12:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 20:04:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_free_player(t_player *player, t_mlx mlx)
{
	if (player == NULL || mlx.mlx == NULL)
		return ;
	so_long_free_image(&player->frames[UP], mlx);
	so_long_free_image(&player->frames[LEFT], mlx);
	so_long_free_image(&player->frames[DOWN], mlx);
	so_long_free_image(&player->frames[RIGHT], mlx);
	ft_free((void **)&player->frames);
}

void	so_long_free_frames(t_image **frames, t_mlx mlx, int size)
{
	if (frames == NULL || mlx.mlx == NULL)
		return ;
	while (size-- > 0)
		so_long_free_image(&(*frames)[size], mlx);
	ft_free((void **)frames);
}
