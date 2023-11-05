/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:02:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 11:02:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

t_std_d	std_dir_init_bonus(void)
{
	t_std_d	std;

	std.bck = "textures/bck.xpm";
	std.col = "textures/col.xpm";
	std.ext = "textures/ext.xpm";
	std.wal = "textures/wal.xpm";
	return (std);
}

t_play_d	play_dir_init_bonus(void)
{
	t_play_d	play;

	play.play = "textures/play.xpm";
	play.play_r = "textures/play_r.xpm";
	play.play_l = "textures/play_l.xpm";
	play.play_u = "textures/play_u.xpm";
	play.play_d = "textures/play_d.xpm";
	return (play);
}

t_fire_d	fire_dir_init_bonus(void)
{
	t_fire_d	fire;

	fire.fire_1 = "textures/fire_1.xpm";
	fire.fire_2 = "textures/fire_2.xpm";
	fire.fire_3 = "textures/fire_3.xpm";
	fire.fire_4 = "textures/fire_4.xpm";
	fire.fire_5 = "textures/fire_5.xpm";
	return (fire);
}

t_dir	dir_init_bonus(void)
{
	t_dir	dir;

	dir.play = play_dir_init_bonus();
	dir.std = std_dir_init_bonus();
	dir.fire = fire_dir_init_bonus();
	return (dir);
}
