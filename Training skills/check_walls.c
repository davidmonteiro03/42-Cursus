/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:24:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 11:34:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_adj
{
	char	a1;
	char	a2;
	char	a3;
	char	b1;
	char	b3;
	char	c1;
	char	c2;
	char	c3;
}t_adj;

size_t	get_max_len(char **map, int i)
{
	size_t	max_len;

	max_len = 0;
	while (map[++i])
		if (strlen(map[i]) > max_len)
			max_len = strlen(map[i]);
	return (max_len);
}

int	strs_size(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		;
	return (i);
}

char	**construct_map(void)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * 14);
	map[0] =  strdup("        1111111111111111111111111");
	map[1] =  strdup("       11000001000110000000000001");
	map[2] =  strdup("        1011000001110000000000001");
	map[3] =  strdup("        1001000000100000000001111");
	map[4] =  strdup("111111  10110001111111111111111 ");
	map[5] =  strdup("1111011 11111101 100000010001   ");
	map[6] =  strdup("1111011 11111111 101010010001   ");
	map[7] =  strdup("11000000110101011100000010001   ");
	map[8] =  strdup("10000000000000000000000010001   ");
	map[9] =  strdup("10000000000000011101010010001   ");
	map[10] = strdup("1100000111010101 111011110N0111 ");
	map[11] = strdup("11110111 1110101 101111010001   ");
	map[12] = strdup("11111111 1111111 111111111111   ");
	map[13] = NULL;
	return (map);
}

char	**copy(char **map, int i, int max_len)
{
	char	**save;
	int		j;

	save = (char **)malloc(sizeof(char *) * (strs_size(map) + 1));
	while (map[++i])
	{
		save[i] = (char *)malloc(sizeof(char) * (max_len + 1));
		j = -1;
		while (++j < max_len)
		{
			if (j < (int)strlen(map[i]))
				save[i][j] = map[i][j];
			else
				save[i][j] = ' ';
		}
		save[i][j] = '\0';
	}
	save[i] = NULL;
	return (save);
}

void	update(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = strs[i - 1][j - 1];
	adj->a2 = strs[i - 1][j];
	adj->a3 = strs[i - 1][j + 1];
	adj->b1 = strs[i][j - 1];
	adj->b3 = strs[i][j + 1];
	adj->c1 = strs[i + 1][j - 1];
	adj->c2 = strs[i + 1][j];
	adj->c3 = strs[i + 1][j + 1];
}

void	update1(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = ' ';
	adj->a2 = ' ';
	adj->a3 = ' ';
	adj->b1 = ' ';
	adj->b3 = strs[i][j + 1];
	adj->c1 = ' ';
	adj->c2 = strs[i + 1][j];
	adj->c3 = strs[i + 1][j + 1];
}

void	update2(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = ' ';
	adj->a2 = ' ';
	adj->a3 = ' ';
	adj->b1 = strs[i][j - 1];
	adj->b3 = ' ';
	adj->c1 = strs[i + 1][j - 1];
	adj->c2 = strs[i + 1][j];
	adj->c3 = ' ';
}

void	update3(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = ' ';
	adj->a2 = ' ';
	adj->a3 = ' ';
	adj->b1 = strs[i][j - 1];
	adj->b3 = strs[i][j + 1];
	adj->c1 = strs[i + 1][j - 1];
	adj->c2 = strs[i + 1][j];
	adj->c3 = strs[i + 1][j + 1];
}

void	update4(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = ' ';
	adj->a2 = strs[i - 1][j];
	adj->a3 = strs[i - 1][j + 1];
	adj->b1 = ' ';
	adj->b3 = ' ';
	adj->c1 = ' ';
	adj->c2 = ' ';
	adj->c3 = ' ';
}

void	update5(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = strs[i - 1][j - 1];
	adj->a2 = strs[i - 1][j];
	adj->a3 = ' ';
	adj->b1 = strs[i][j - 1];
	adj->b3 = ' ';
	adj->c1 = ' ';
	adj->c2 = ' ';
	adj->c3 = ' ';
}

void	update6(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = strs[i - 1][j - 1];
	adj->a2 = strs[i - 1][j];
	adj->a3 = strs[i - 1][j + 1];
	adj->b1 = strs[i][j - 1];
	adj->b3 = strs[i][j + 1];
	adj->c1 = ' ';
	adj->c2 = ' ';
	adj->c3 = ' ';
}

void	update7(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = ' ';
	adj->a2 = strs[i - 1][j];
	adj->a3 = strs[i - 1][j + 1];
	adj->b1 = ' ';
	adj->b3 = strs[i][j + 1];
	adj->c1 = ' ';
	adj->c2 = strs[i + 1][j];
	adj->c3 = strs[i + 1][j + 1];
}

void	update8(t_adj *adj, char **strs, int i, int j)
{
	adj->a1 = strs[i - 1][j - 1];
	adj->a2 = strs[i - 1][j];
	adj->a3 = ' ';
	adj->b1 = strs[i][j - 1];
	adj->b3 = ' ';
	adj->c1 = strs[i + 1][j - 1];
	adj->c2 = strs[i + 1][j];
	adj->c3 = ' ';
}

bool	check_wall(t_adj adj, char c)
{
	if (adj.b1 == ' ' || adj.b3 == ' ' || \
		adj.a2 == ' ' || adj.c2 == ' ')
	{
		if (c == '1')
			return (true);
		else
			return (false);
	}
	return (true);
}

bool	check(char **strs, int i, int j)
{
	t_adj	adj;

	if (i == 0)
	{
		if (j == 0)
			return (update1(&adj, strs, i, j), check_wall(adj, strs[i][j]));
		if (j == (int)strlen(strs[i]) - 1)
			return (update2(&adj, strs, i, j), check_wall(adj, strs[i][j]));
		return (update3(&adj, strs, i, j), check_wall(adj, strs[i][j]));
	}
	if (i == (int)strs_size(strs) - 1)
	{
		if (j == 0)
			return (update4(&adj, strs, i, j), check_wall(adj, strs[i][j]));
		if (j == (int)strlen(strs[i]) - 1)
			return (update5(&adj, strs, i, j), check_wall(adj, strs[i][j]));
		return (update6(&adj, strs, i, j), check_wall(adj, strs[i][j]));
	}
	if (j == 0)
		return (update7(&adj, strs, i, j), check_wall(adj, strs[i][j]));
	if (j == (int)strlen(strs[i]) - 1)
		return (update8(&adj, strs, i, j), check_wall(adj, strs[i][j]));
	return (update(&adj, strs, i, j), check_wall(adj, strs[i][j]));
}

bool	check_walls(char **strs, int i)
{
	int	j;

	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (strs[i][j] == ' ')
				continue ;
			if (!check(strs, i, j))
				return (false);
		}
	}
	return (true);
}

int	main(void)
{
	char	**map;
	char	**save;
	int		max_len;
	int		i;

	map = construct_map();
	max_len = get_max_len(map, -1);
	save = copy(map, -1, max_len);
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	if (check_walls(save, -1))
		printf("OK\n");
	else
		printf("KO\n");
	i = -1;
	while (save[++i])
		free(save[i]);
	free(save);
	return (0);
}
