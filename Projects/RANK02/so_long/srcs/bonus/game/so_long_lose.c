/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:48:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_lose(t_game *game, char c)
{
	if (c == STATIC_ENEMY)
		ft_putendl_fd(LOSE_REASON_1, STDOUT_FILENO);
	else if (c == MOVING_ENEMY)
		ft_putendl_fd(LOSE_REASON_2, STDOUT_FILENO);
	so_long_close(game);
}
