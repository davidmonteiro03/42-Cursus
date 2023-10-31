/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:15:39 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 12:41:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mapinfo_update(char c, t_mapinfo *mapinfo, t_chars chars)
{
	if (c == chars.collect)
		mapinfo->n_collect++;
	else if (c == chars.exit)
		mapinfo->n_exit++;
	else if (c == chars.start_pos)
		mapinfo->n_start_pos++;
}
