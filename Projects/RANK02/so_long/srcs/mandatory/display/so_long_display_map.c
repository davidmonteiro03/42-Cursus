/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:29:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_display_map(t_map map, bool debug)
{
	int	i;

	if (map.content == NULL)
		return ;
	i = -1;
	while (map.content[++i] != NULL)
	{
		if (debug == true)
			ft_printf("line %d:", i);
		ft_printf("%s\n", map.content[i]);
	}
}
