/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:07:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 10:17:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	start;

	if (a == 0 || b == 0)
		return (0);
	start = 1;
	while (1)
	{
		if (start % a == 0 && start % b == 0)
			break ;
		start++;
	}
	return (start);
}
