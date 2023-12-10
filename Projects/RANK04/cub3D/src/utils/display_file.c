/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:13:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 21:00:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_display_strs(char **file_content, int start, int end)
{
	while (start <= end)
	{
		if (*file_content[start])
			printf("%s\n", file_content[start]);
		start++;
	}
}
