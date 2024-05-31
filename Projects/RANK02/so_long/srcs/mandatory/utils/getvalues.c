/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:16:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:07:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	ft_minvalue(int value_a, int value_b)
{
	if (value_b < value_a)
		return (value_b);
	return (value_a);
}

int	ft_maxvalue(int value_a, int value_b)
{
	if (value_b > value_a)
		return (value_b);
	return (value_a);
}
