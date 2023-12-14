/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:37:59 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 21:48:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

t_parse	cub_init_parse(void)
{
	t_parse	parse;

	parse.up = 0;
	parse.left = 0;
	parse.right = 0;
	parse.down = 0;
	parse.spc_up = 0;
	parse.spc_left = 0;
	parse.spc_right = 0;
	parse.spc_down = 0;
	return (parse);
}

bool	cub_check_space(t_parse parse, char c)
{
	return (parse.up != parse.spc_up && parse.left != parse.spc_left && \
		parse.right != parse.spc_right && parse.down != parse.spc_down && \
		c == '-');
}

void	cub_check_char(char **strs, int i, int j)
{
	int		k;
	int		l;
	t_parse	parse;

	parse = cub_init_parse();
	k = -1;
	while (strs[++k])
	{
		l = -1;
		while (strs[k][++l])
		{
			if (k == i && l == j)
				continue ;
			if (k < i && l == j)
				cub_update_parse_up(&parse, strs, k, l);
			else if (k == i && l < j)
				cub_update_parse_left(&parse, strs, k, l);
			else if (k == i && l > j)
				cub_update_parse_right(&parse, strs, k, l);
			else if (k > i && l == j)
				cub_update_parse_down(&parse, strs, k, l);
		}
	}
	if (cub_check_space(parse, strs[i][j]))
		strs[i][j] = ' ';
}

void	cub_prepare_copy(char **strs, int i)
{
	int	j;

	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			cub_check_char(strs, i, j);
	}
}
