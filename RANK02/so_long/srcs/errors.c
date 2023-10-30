/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:16:05 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 19:20:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	simperror(char *error)
{
	if (!error)
		ft_putendl_fd("Error", 2);
	else
		ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}
