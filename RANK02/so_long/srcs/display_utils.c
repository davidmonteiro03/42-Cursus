/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:49:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 16:59:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_1(int c, int t, int p)
{
	ft_printf(LEVEL_1 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_1 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_1 " Too low" BWHT " ☹️\n" RESET);
}

void	display_2(int c, int t, int p)
{
	ft_printf(LEVEL_2 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_2 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_2 " Low" BWHT " 🙁\n" RESET);
}

void	display_3(int c, int t, int p)
{
	ft_printf(LEVEL_3 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_3 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_3 " Ok" BWHT "... 😐\n" RESET);
}

void	display_4(int c, int t, int p)
{
	ft_printf(LEVEL_4 "%d" BWHT "/" BCYN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_4 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_4 " Good job" BWHT "! 🙂\n" RESET);
}

void	display_5(int c, int t, int p)
{
	ft_printf(LEVEL_5 "%d" BWHT "/" BGRN "%d", c, t);
	ft_printf(BWHT " (" LEVEL_5 "%d%%" BWHT ")", p);
	ft_printf(LEVEL_5 " Wow" BWHT "! " LEVEL_5 "You're amazing" \
		BWHT "! 😀\n" RESET);
}
