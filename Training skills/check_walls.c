/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:24:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 01:13:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	get_max_len(char **map, int i)
{
	int	max_len;

	max_len = 0;
	while (map[++i])
		if (strlen(map[i]) > max_len)
			max_len = strlen(map[i]);
	return (max_len);
}

char	**construct_map(void)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * 15);
	map[0] =  strdup("111     1111111111111111111111111");
	map[1] =  strdup("101  1  1000    00110000000000001");
	map[2] =  strdup("111 111 1011000001110000000000001");
	map[3] =  strdup("     1  1001000000000000000000001");
	map[4] =  strdup("111111111011000001110000000000001");
	map[5] =  strdup("100000000011000001110111111111111");
	map[6] =  strdup("11110111111111011100000010001");
	map[7] =  strdup("11110111111111011101010010001");
	map[8] =  strdup("110000     101011100000010001");
	map[9] =  strdup("10000000000000001100000010001");
	map[10] = strdup("10000000000000001101010010001");
	map[11] = strdup("11000001110101011111011110N0111");
	map[12] = strdup("11110111 1110101 101111010001");
	map[13] = strdup("  111111 1111111 111111111111");
	map[14] = NULL;
	return (map);
}

char	**copy(char **map, int i, int max_len)
{
	char	**save;
	int		j;

	save = (char **)malloc(sizeof(char *) * 15);
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

int	strs_size(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		;
	return (i);
}

void	check_adj(char a1, char a2, char a3, \
	char b1, char b3, \
	char c1, char c2, char c3)
{
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("+"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("|"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (!strchr(" \0", a1) && !strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && !strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (!strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && !strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		!strchr(" \0", c1) && strchr(" \0", c2) && strchr(" \0", c3))
		return (printf("-"), (void)0);
	if (strchr(" \0", a1) && strchr(" \0", a2) && strchr(" \0", a3) && \
		!strchr(" \0", b1) && !strchr(" \0", b3) && \
		strchr(" \0", c1) && strchr(" \0", c2) && !strchr(" \0", c3))
		return (printf("-"), (void)0);
	printf(" ");
}

void	check_pos(char **strs, int i, int j)
{
	if (i == 0)
	{
		if (j == 0)
		{
			check_adj(' ', ' ', ' ', \
				' ', strs[i][j + 1], \
				' ', strs[i + 1][j], strs[i + 1][j + 1]);
			return ;
		}
		if (j == (int)strlen(strs[i]) - 1)
		{
			check_adj(' ', ' ', ' ', \
				strs[i][j - 1], ' ', \
				strs[i + 1][j - 1], strs[i + 1][j], ' ');
			return ;
		}
		check_adj(' ', ' ', ' ', \
			strs[i][j - 1], strs[i][j + 1], \
			strs[i + 1][j - 1], strs[i + 1][j], strs[i + 1][j + 1]);
		return ;
	}
	if (i == (int)strs_size(strs) - 1)
	{
		if (j == 0)
		{
			check_adj(' ', strs[i - 1][j], strs[i - 1][j + 1], \
				' ', ' ', \
				' ', ' ', ' ');
			return ;
		}
		if (j == (int)strlen(strs[i]) - 1)
		{
			check_adj(strs[i - 1][j - 1], strs[i - 1][j], ' ', \
				strs[i][j - 1], ' ', \
				' ', ' ', ' ');
			return ;
		}
		check_adj(strs[i - 1][j - 1], strs[i - 1][j], strs[i - 1][j + 1], \
			strs[i][j - 1], strs[i][j + 1], \
			' ', ' ', ' ');
		return ;
	}
	if (j == 0)
	{
		check_adj(' ', strs[i - 1][j], strs[i - 1][j + 1], \
			' ', strs[i][j + 1], \
			' ', strs[i + 1][j], strs[i + 1][j + 1]);
		return ;
	}
	if (j == (int)strlen(strs[i]) - 1)
	{
		check_adj(strs[i - 1][j - 1], strs[i - 1][j], ' ', \
			strs[i][j - 1], ' ', \
			strs[i + 1][j - 1], strs[i + 1][j], ' ');
		return ;
	}
	check_adj(strs[i - 1][j - 1], strs[i - 1][j], strs[i - 1][j + 1], \
		strs[i][j - 1], strs[i][j + 1], \
		strs[i + 1][j - 1], strs[i + 1][j], strs[i + 1][j + 1]);
}

void	display_strs(char **strs, int i)
{
	int	j;

	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			if (strs[i][j] == ' ')
			{
				printf(" ");
				continue ;
			}
			check_pos(strs, i, j);
		}
		printf("\n");
	}
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
	display_strs(save, -1);
	i = -1;
	while (save[++i])
		free(save[i]);
	free(save);
	return (0);
}
