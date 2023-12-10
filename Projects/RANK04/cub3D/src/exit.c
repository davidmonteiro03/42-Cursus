/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:44:01 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 09:46:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_exit(t_cub *cub)
{
	multiple_free("%c%b%a", cub->config.data.data, \
		cub->config.data.file_content, cub);
	exit(0);
}
