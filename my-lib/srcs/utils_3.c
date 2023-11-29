/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:03:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/29 10:27:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

void	send_to_trash(t_gb *gb)
{
	if (!gb)
		return ;
	if (gb->ln)
		free(gb->ln);
	if (gb->cm)
		free(gb->cm);
	if (gb->as)
		multiple_free("%b", gb->as);
	if (gb->ag)
		multiple_free("%b", gb->ag);
	free(gb);
}
