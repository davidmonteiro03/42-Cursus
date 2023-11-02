/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:10:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/02 13:39:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	prep_game(t_game *g, char **m, t_mapinfo info)
{
	int	i;
	int	j;

	g->c = 0;
	g->tc = info.n_collect;
	g->x = info.start_x;
	g->y = info.start_y;
	g->m = (char **)malloc(sizeof(char *) * (info.n_lines + 1));
	i = -1;
	while (++i < info.n_lines)
	{
		g->m[i] = (char *)malloc(sizeof(char) * (info.n_columns + 1));
		j = -1;
		while (++j < info.n_columns)
			g->m[i][j] = m[i][j];
		g->m[i][j] = '\0';
	}
	g->m[i] = NULL;
}

void	start_game(t_game *g)
{
	system("clear");
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return ;
	g->win = mlx_new_window(g->mlx, 600, 600, \
		"so_long");
	if (g->win == NULL)
	{
		free(g->mlx);
		return ;
	}
	mlx_loop_hook(g->mlx, &handle_no_event, g);
	mlx_key_hook(g->win, &handle_input, g);
	mlx_loop(g->mlx);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

void	end_game(t_game *g)
{
	system("clear");
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	display_strs(g->m);
	multiple_free("%b", g->m);
	exit(EXIT_SUCCESS);
}
