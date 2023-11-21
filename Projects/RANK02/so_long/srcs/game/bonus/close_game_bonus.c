/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:35:41 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 16:35:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

int	close_game_bonus(t_game *g)
{
	clean_imgs_bonus(g);
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
	multiple_free("%b", g->data.m);
	print_exit_msg();
	exit(EXIT_SUCCESS);
	return (0);
}

int	lose_game_bonus(t_game *g)
{
	clean_imgs_bonus(g);
	mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
	multiple_free("%b", g->data.m);
	print_lose_msg();
	print_game_info(g);
	exit(EXIT_SUCCESS);
	return (0);
}
