/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:36:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 17:02:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_exit(t_cub *cub)
{
	free_img(cub->directions.north);
	free_img(cub->directions.south);
	free_img(cub->directions.west);
	free_img(cub->directions.east);
	free_file(cub->config);
	free(cub);
	exit(0);
}
