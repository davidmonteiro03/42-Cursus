/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:54:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/09 19:55:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	cub_swap_strs(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	cub_strs_sort(char ***strs_ptr, int i)
{
	int	j;

	while ((*strs_ptr)[++i])
	{
		j = i;
		while ((*strs_ptr)[++j])
			if (!ft_strnstr((*strs_ptr)[i], ".xpm", \
				ft_strlen((*strs_ptr)[i])) && \
				ft_strnstr((*strs_ptr)[j], ".xpm", \
				ft_strlen((*strs_ptr)[j])))
				cub_swap_strs(&(*strs_ptr)[i], &(*strs_ptr)[j]);
	}
}
