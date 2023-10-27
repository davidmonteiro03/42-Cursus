/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/27 18:49:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(void)
{
	ft_printf(BCYN "Server PID" BWHT ": " BGRN "%d" BWHT "\n", getpid());
	while (1)
		pause();
	return (0);
}
