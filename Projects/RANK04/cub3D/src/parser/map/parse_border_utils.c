/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_border_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:19:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 14:13:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_update_parse_up(t_parse *parse, char **strs, int k, int l)
{
	parse->up++;
	if (strs[k][l] == '-')
		parse->spc_up++;
}

void	cub_update_parse_left(t_parse *parse, char **strs, int k, int l)
{
	parse->left++;
	if (strs[k][l] == '-')
		parse->spc_left++;
}

void	cub_update_parse_right(t_parse *parse, char **strs, int k, int l)
{
	parse->right++;
	if (strs[k][l] == '-')
		parse->spc_right++;
}

void	cub_update_parse_down(t_parse *parse, char **strs, int k, int l)
{
	parse->down++;
	if (strs[k][l] == '-')
		parse->spc_down++;
}

void	cub_little_update(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			if (strs[i][j] == ' ')
				strs[i][j] = '-';
	}
}
