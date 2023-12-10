/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:15:09 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 15:02:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_set_config_util(t_cub *cub, char **strs, int i, int count)
{
	char	*tmp;

	cub->config.data.data = (char ***)malloc(sizeof(char **) * 7);
	cub->config.data.data[6] = NULL;
	while (strs[++i])
	{
		tmp = cub_get_config(strs[i], 0);
		if (!tmp)
			continue ;
		cub->config.data.data[count++] = ft_split(tmp, ' ');
		free(tmp);
	}
}

void	cub_set_color(t_cub *cub, char **strs, char *type, int i)
{
	char	*buf;
	char	**tmp;

	buf = ft_strdup("");
	while (strs[++i])
		buf = cub_buildfree(buf, ft_strdup(strs[i]), &ft_strjoin);
	tmp = ft_split(buf, ',');
	free(buf);
	if (!cub_strcmp(type, "F"))
		cub->config.floor = cub_get_color(tmp);
	else
		cub->config.ceiling = cub_get_color(tmp);
	multiple_free("%b", tmp);
}

void	cub_set_config(t_cub *cub, char ***data, int i)
{
	while (data[++i])
		if (!cub_strcmp(data[i][0], "F") || !cub_strcmp(data[i][0], "C"))
			cub_set_color(cub, &data[i][1], data[i][0], -1);
	cub->mlx.mlx = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, 600, 600, "Cub3D");
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_key_handler, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_loop(cub->mlx.mlx);
}
