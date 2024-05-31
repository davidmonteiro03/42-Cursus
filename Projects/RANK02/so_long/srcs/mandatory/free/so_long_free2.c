/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:12:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

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
