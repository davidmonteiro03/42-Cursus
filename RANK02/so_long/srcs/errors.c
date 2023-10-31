/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:16:05 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 09:53:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	simperror(char *error)
{
	ft_putendl_fd("Error", 2);
	if (error)
		ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	fileerror(char *file)
{
	perror(file);
	multiple_free("%a", file);
	exit(EXIT_FAILURE);
}
