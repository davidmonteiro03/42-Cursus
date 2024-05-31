/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireballs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:02:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/06 19:32:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

t_fireball	*ft_newfireball(t_pos pos, int direction)
{
	t_fireball	*fireball;

	fireball = (t_fireball *)malloc(sizeof(t_fireball));
	if (fireball == NULL)
		return (NULL);
	fireball->pos = pos;
	fireball->direction = direction;
	return (fireball);
}
