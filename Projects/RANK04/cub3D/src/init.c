/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:44:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 21:28:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_count	cub_count_init(void)
{
	t_count	count;

	count.count_map = 0;
	count.count_config = 0;
	return (count);
}

t_file	cub_file_init(void)
{
	t_file	file;

	file.fd = 0;
	file.filename = NULL;
	file.content = NULL;
	return (file);
}

t_cub	*cub_init(void)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	cub->config = cub_file_init();
	cub->count = cub_count_init();
	return (cub);
}
