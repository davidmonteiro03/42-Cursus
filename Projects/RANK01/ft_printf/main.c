/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:16:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 17:30:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("%.5s", "ola mundo");
	printf("$\n");
	fflush(stdout);
	ft_printf("%.5s", "ola mundo");
	printf("$\n");
	return (0);
}
