/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:52:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 17:39:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	tmp_simple_display(char **strs, int i, int j)
{
	write(1, "=========== IGNORE ========= ", 29);
	while (strs[i][++j])
	{
		if (strs[i][j] == ' ')
			write(1, "-", 1);
		else
			write(1, &strs[i][j], 1);
	}
	write(1, "\n", 1);
}

void	display_before(char **strs, int i)
{
	int	k;

	write(1, "\n---- BEFORE ------\n", 20);
	k = -1;
	while (++k < i)
	{
		write(1, strs[k], ft_strlen(strs[k]));
		write(1, "\n", 1);
	}
	write(1, "---- CURRENT ------\n", 20);
}

void	display_after(char **strs, int i)
{
	int	k;

	write(1, "\n----  AFTER  ------\n", 21);
	k = i;
	while (++k < cub_strs_size(strs))
	{
		write(1, strs[k], ft_strlen(strs[k]));
		write(1, "\n", 1);
	}
	write(1, "---- CURRENT ------\n", 20);
}

void	tmp_ultimate_display(char **strs, int i, int j)
{
	write(1, "========== CONSIDER ======== ", 30);
	display_before(strs, i);
	while (strs[i][++j])
	{
		if (strs[i][j] == ' ')
			write(1, "-", 1);
		else
			write(1, &strs[i][j], 1);
	}
	display_after(strs, i);
	write(1, "\n", 1);
}

void	cub_check_walls(char **strs, int i)
{
	while (strs[++i])
	{
		if (i == 0 || i == cub_strs_size(strs) - 1)
			tmp_simple_display(strs, i, -1);
		else
			tmp_ultimate_display(strs, i, -1);
	}
}

void cub_check_border(t_cub *cub, int start, int end)
{
	char	**map;
	char	**copy;

	map = cub_get_lines(cub->config.content, start, end);
	copy = cub_copy(map, -1, cub_get_max_len(map, -1));
	multiple_free("%b", map);
	cub_check_walls(copy, -1);
	multiple_free("%b", copy);
}

/*
MAP:
        11111111          1111111
        1000000111  111111 01
        1011000001110000000001111
        1001000000000000000000001
111 11111011000001110000000000001
101 10000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
1100         1011100000010001
10000000000000001100000010001
1000000000000000110101001000111111111111
11000001110101011111011110N0000000000001
11110111 1110101 10111101000111111111111
11111111 1111111 111111111111

BORDER:
        11111111          1111111
        1      111  111111  1
        1         11         1111
        1                       1
111 11111                       1
1 1 1                       11111
1  1                        1
1                           1
1                           1
1                           1
1                           111111111111
1       1       1                      1
1      1 1     1 1          111111111111
11111111 1111111 111111111111
*/
