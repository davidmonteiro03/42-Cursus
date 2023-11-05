/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:22:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 19:22:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	print_level1_bonus(int c, int t, int p)
{
	ft_printf(LEVEL_1 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_1 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_1 " Too low" BWHT "! ☹️\n" RESET);
}

void	print_level2_bonus(int c, int t, int p)
{
	ft_printf(LEVEL_2 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_2 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_2 " You could do better" BWHT "... 🙁\n" RESET);
}

void	print_level3_bonus(int c, int t, int p)
{
	ft_printf(LEVEL_3 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_3 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_3 " Ok" BWHT "... 😐\n" RESET);
}

void	print_level4_bonus(int c, int t, int p)
{
	ft_printf(LEVEL_4 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_4 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_4 " Good job" BWHT ". 🙂\n" RESET);
}

void	print_level5_bonus(int c, int t, int p)
{
	ft_printf(LEVEL_5 "%d" BWHT "/" LEVEL_5 "%d", c, t);
	ft_printf(BWHT " (" LEVEL_5 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_5 " Wow" BWHT "! " LEVEL_5 "Your're amazing" \
		BWHT "! 😀\n" RESET);
}
