/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:14:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 17:11:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		ft_printf("%s\n", strs[i]);
}

void	display_chars_struct(t_chars chars)
{
	ft_printf("empty    : %c\n", chars.empty);
	ft_printf("wall     : %c\n", chars.wall);
	ft_printf("collect  : %c\n", chars.collect);
	ft_printf("exit     : %c\n", chars.exit);
	ft_printf("start_pos: %c\n", chars.start_pos);
}

static void	display_c(t_game *g)
{
	int	p;
	int	c;
	int	t;

	c = g->sc - g->c;
	t = g->sc;
	p = (double)c / (double)t * 100;
	if (p < 20)
		display_1(c, t, p);
	else if (p < 50)
		display_2(c, t, p);
	else if (p < 70)
		display_3(c, t, p);
	else if (p < 90)
		display_4(c, t, p);
	else
		display_5(c, t, p);
}

void	display_game_info(t_game *g)
{
	ft_printf(BCYN "\nGAME INFO\n");
	ft_printf(BCYN "x" BWHT ": " BGRN "%d", g->x);
	ft_printf(BCYN " y" BWHT ": " BGRN "%d", g->y);
	ft_printf(BCYN "\nCollected" BWHT ": ");
	display_c(g);
	ft_printf("\n" RESET);
}
