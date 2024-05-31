/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_display_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:29:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_display_file(t_file file, bool debug)
{
	int	i;

	if (file.content == NULL)
		return ;
	i = -1;
	while (file.content[++i] != NULL)
	{
		if (debug == true)
			ft_printf("line %d:", i);
		ft_printf("%s\n", file.content[i]);
	}
}
