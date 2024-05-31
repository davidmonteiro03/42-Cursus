/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:51:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 14:03:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	so_long_check_frames(t_game *game)
{
	if (game->sprites.elapsed_time[FRM] >= 1.0 / MAX_FRAMES)
	{
		game->sprites.frames[COL]++;
		game->sprites.frames[SEN]++;
		game->sprites.frames[MEN]++;
		game->sprites.frames[FRB]++;
		gettimeofday(&game->sprites.time[FRM].start, NULL);
	}
}

void	so_long_update_time(t_time *time, double *elapsed_time)
{
	ft_bzero(&time->end, sizeof(time->end));
	if (time->start.tv_sec == 0 && time->start.tv_usec == 0)
		gettimeofday(&time->start, NULL);
	gettimeofday(&time->end, NULL);
	*elapsed_time = (time->end.tv_sec - time->start.tv_sec) + \
		((time->end.tv_usec - time->start.tv_usec) / 1000000.0);
}

void	so_long_update_times(t_game *game)
{
	so_long_update_time(&game->sprites.time[FRM], \
		&game->sprites.elapsed_time[FRM]);
	so_long_update_time(&game->sprites.time[ENE], \
		&game->sprites.elapsed_time[ENE]);
	so_long_update_time(&game->sprites.time[SPL], \
		&game->sprites.elapsed_time[SPL]);
}
