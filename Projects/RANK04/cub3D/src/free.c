/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:41:44 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 19:25:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_file(t_file file)
{
	if (file.filename)
		free(file.filename);
	if (file.content && *file.content)
		multiple_free("%b", file.content);
	else if (file.content)
		free(file.content);
}
