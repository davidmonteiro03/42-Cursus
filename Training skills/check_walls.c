/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:24:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 20:11:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	get_max_len(char **map)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if (strlen(map[i]) > max_len)
			max_len = strlen(map[i]);
		i++;
	}
	return (max_len);
}

char	**construct_map(void)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * 15);
	map[0] =  strdup("        1111111111111111111111111");
	map[1] =  strdup("        1000000000110000000000001");
	map[2] =  strdup("        1011000001110000000000001");
	map[3] =  strdup("        1001000000000000000000001");
	map[4] =  strdup("111111111011000001110000000000001");
	map[5] =  strdup("100000000011000001110111111111111");
	map[6] =  strdup("11110111111111011100000010001");
	map[7] =  strdup("11110111111111011101010010001");
	map[8] =  strdup("11000000110101011100000010001");
	map[9] =  strdup("10000000000000001100000010001");
	map[10] = strdup("10000000000000001101010010001");
	map[11] = strdup("11000001110101011111011110N0111");
	map[12] = strdup("11110111 1110101 101111010001");
	map[13] = strdup("  111111 1111111 111111111111");
	map[14] = NULL;
	return (map);
}

int	main(void)
{
	char	**map;
	int		max_len;
	int		i;

	map = construct_map();
	max_len = get_max_len(map);
	printf("max_len: %d\n", max_len);
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}
