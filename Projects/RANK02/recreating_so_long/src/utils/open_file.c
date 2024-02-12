/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:38:26 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 19:50:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	so_long_open_file(char *arg)
{
	int	tmp_fd;

	tmp_fd = open(arg, O_RDONLY);
	if (tmp_fd < 0)
		return (false);
	return (close(tmp_fd), true);
}
