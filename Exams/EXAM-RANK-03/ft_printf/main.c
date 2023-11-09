/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:18:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:19:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// choose your arguments
int	main(void)
{
	printf("%d\n", \
		ft_printf("%s %d %x %d %s\n", NULL, 42, 42, 100, "Hello World!") \
	);
	return (0);
}
