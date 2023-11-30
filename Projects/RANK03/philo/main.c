/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 17:49:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int c, char **v)
{
	t_dt	*dt;

	if (c != 5 && c != 6)
		return (1);
	if (ph_chk(-1, v + 1))
		return (1);
	dt = NULL;
	if (ph_din(&dt, v + 1))
		return (1);
	if (ph_pin(&dt, -1))
		return (1);
	ph_run(dt);
	ph_clr(&dt, -1);
	return (0);
}
