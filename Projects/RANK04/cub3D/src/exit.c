/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:36:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 19:32:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	cub_exit(t_cub *cub)
{
	free_mlx_imgs(cub);
	free_mlx(cub->mlx);
	free_img(cub->directions.north);
	free_img(cub->directions.south);
	free_img(cub->directions.west);
	free_img(cub->directions.east);
	free_file(cub->config);
	free_map(cub->map);
	free(cub);
	exit(0);
}
