/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:16:05 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 17:05:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	simperror(char *error)
{
	ft_printf(BRED);
	ft_putendl_fd("Error" , 2);
	if (error)
		ft_putendl_fd(error, 2);
	ft_printf(RESET);
	exit(EXIT_FAILURE);
}

void	fileerror(char *file)
{
	ft_printf(BRED);
	perror(file);
	multiple_free("%a", file);
	ft_printf(RESET);
	exit(EXIT_FAILURE);
}
