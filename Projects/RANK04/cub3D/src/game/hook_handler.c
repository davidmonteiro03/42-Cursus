/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:35:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 19:46:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->keys.w = true;
	else if (keycode == XK_s)
		cub->keys.s = true;
	else if (keycode == XK_a)
		cub->keys.a = true;
	else if (keycode == XK_d)
		cub->keys.d = true;
	else if (keycode == XK_Left)
		cub->keys.left = true;
	else if (keycode == XK_Right)
		cub->keys.right = true;
	else if (keycode == XK_Escape)
		cub->keys.esc = true;
	return (0);
}

int	cub_key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->keys.w = false;
	else if (keycode == XK_s)
		cub->keys.s = false;
	else if (keycode == XK_a)
		cub->keys.a = false;
	else if (keycode == XK_d)
		cub->keys.d = false;
	else if (keycode == XK_Left)
		cub->keys.left = false;
	else if (keycode == XK_Right)
		cub->keys.right = false;
	else if (keycode == XK_Escape)
		cub->keys.esc = false;
	return (0);
}
