/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:14:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 16:06:18 by dcaetano         ###   ########.fr       */
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

void	display_game(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			write(1, &game->map[i][j], 1);
		write (1, "\n", 1);
	}
	ft_printf("\nINFO\n");
	ft_printf("col: %d/%d\n", game->c, game->total_c);
}
