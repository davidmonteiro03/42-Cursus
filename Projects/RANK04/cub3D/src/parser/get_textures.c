/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:01:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/09 22:23:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_count_textures(char **strs, int count)
{
	char	**tmp;

	while (ft_strnstr(strs[count], ".xpm", ft_strlen(strs[count])))
	{
		tmp = ft_split(strs[count], ' ');
		if (!tmp)
			return (0);
		if (!*tmp)
			return (free(tmp), 0);
		if (!tmp[1] || tmp[2])
			return (multiple_free("%b", tmp), 0);
		multiple_free("%b", tmp);
		count++;
	}
	return (count);
}

void	cub_get_textures(t_cub *cub, char **strs, int i)
{
	char	**tmp_strs;
	int		count;

	tmp_strs = strs;
	count = cub_count_textures(strs, 0);
	if (count != 4)
		return (multiple_free("%b", tmp_strs), \
			cub_error_parsing(cub, ERROR_TEXTURES));
	cub->textures.textures = (char ***)malloc(sizeof(char **) * 5);
	while (ft_strnstr(*strs, ".xpm", ft_strlen(*strs)))
		cub->textures.textures[++i] = ft_split(*strs++, ' ');
	cub->textures.textures[4] = NULL;
	multiple_free("%b", tmp_strs);
}

bool	cub_check_textures(char ***strs, int i)
{
	auto int no_count = 0;
	auto int so_count = 0;
	auto int we_count = 0;
	auto int ea_count = 0;
	while (++i < 4)
	{
		if (!cub_strcmp("NO", strs[i][0]))
			no_count++;
		if (!cub_strcmp("SO", strs[i][0]))
			so_count++;
		if (!cub_strcmp("WE", strs[i][0]))
			we_count++;
		if (!cub_strcmp("EA", strs[i][0]))
			ea_count++;
	}
	return (no_count == 1 && so_count == 1 && we_count == 1 && ea_count == 1);
}
