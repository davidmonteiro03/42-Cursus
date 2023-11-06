/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 19:05:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	check_clear_fire_bonus(t_game *g)
{
	char	*str;
	char	*buff;
	int		i;
	int		j;

	i = -1;
	while (g->data.m[++i])
	{
		j = -1;
		while (g->data.m[i][++j])
			if (g->data.m[i][j] == 'F')
				return ;
	}
	if (g->data.c == 0)
	{
		buff = ft_strdup("MOVES: ");
		str = ft_itoa(g->data.mv);
		buff = ft_jointfree2(buff, str);
		str = ft_strdup(" You collected everything!");
		buff = ft_jointfree2(buff, str);
		put_black_back(g);
		mlx_string_put(g->mlx.mlx, g->mlx.win, 16, g->size.m_h - 10, \
			0xFFFFFF, buff);
		free(buff);
	}
}

void	clear_fire_bonus(t_game *g, int i, int j)
{
	t_chars	c;

	c = chars_init();
	if (g->data.m[i - 1][j - 1] == 'F')
	{
		g->data.m[i - 1][j - 1] = c.empty;
		put_image_bonus(g, g->img.std.bck, (j - 1) * 32, (i - 1) * 32);
	}
	if (g->data.m[i - 1][j + 1] == 'F')
	{
		g->data.m[i - 1][j + 1] = c.empty;
		put_image_bonus(g, g->img.std.bck, (j + 1) * 32, (i - 1) * 32);
	}
	if (g->data.m[i + 1][j - 1] == 'F')
	{
		g->data.m[i + 1][j - 1] = c.empty;
		put_image_bonus(g, g->img.std.bck, (j - 1) * 32, (i + 1) * 32);
	}
	if (g->data.m[i + 1][j + 1] == 'F')
	{
		g->data.m[i + 1][j + 1] = c.empty;
		put_image_bonus(g, g->img.std.bck, (j + 1) * 32, (i + 1) * 32);
	}
	g->data.c--;
}

void	put_fire_pos_bonus(t_game *g, int i, int j)
{
	t_chars	c;

	c = chars_init();
	if (g->data.m[i - 1][j - 1] == c.empty)
		g->data.m[i - 1][j - 1] = 'F';
	if (g->data.m[i - 1][j + 1] == c.empty)
		g->data.m[i - 1][j + 1] = 'F';
	if (g->data.m[i + 1][j - 1] == c.empty)
		g->data.m[i + 1][j - 1] = 'F';
	if (g->data.m[i + 1][j + 1] == c.empty)
		g->data.m[i + 1][j + 1] = 'F';
}
