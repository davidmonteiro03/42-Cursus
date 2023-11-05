/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:17:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 16:17:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	print_exit_msg(void)
{
	ft_printf(RESET "\n");
	ft_printf(BYLW "You left the game" BWHT "... ");
	ft_printf(BYLW "Why" BWHT "??? 😑\n");
	ft_printf("\n" RESET);
}

void	print_score_bonus(t_game *g)
{
	int	c;
	int	t;
	int	p;

	c = g->data.sc - g->data.c;
	t = g->data.sc;
	p = (double)c / (double)t * 100;
	ft_printf(BCYN "Your score\n" RESET);
	if (p < 20)
		print_level1_bonus(c, t, p);
	else if (p < 50)
		print_level2_bonus(c, t, p);
	else if (p < 70)
		print_level3_bonus(c, t, p);
	else if (p < 90)
		print_level4_bonus(c, t, p);
	else
		print_level5_bonus(c, t, p);
}

void	print_game_info(t_game *g)
{
	ft_printf(RESET "\n");
	ft_printf(BCYN "GAME INFO\n\n");
	ft_printf(BCYN "x" BWHT ": " BGRN "%d" BWHT " | " BCYN "y" BWHT ": " \
		BGRN "%d\n" RESET, g->data.x, g->data.y);
	print_score_bonus(g);
	ft_printf("\n" RESET);
}

void	print_lose_msg(t_game *g)
{
	ft_printf(RESET "\n");
	ft_printf(BRED "The fire killed you" BWHT "! " BRED "You lose the game");
	ft_printf(BWHT "... 😥\n");
	print_game_info(g);
}
