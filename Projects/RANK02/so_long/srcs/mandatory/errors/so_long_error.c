/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:50:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:06:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	so_long_error(char *msg, bool usage, bool isfile)
{
	if (usage == true)
	{
		if (msg != NULL)
			ft_putendl_fd(msg, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (msg != NULL)
	{
		ft_putendl_fd(ERROR, STDERR_FILENO);
		if (isfile == true)
			perror(msg);
		else
			ft_putendl_fd(msg, STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}
