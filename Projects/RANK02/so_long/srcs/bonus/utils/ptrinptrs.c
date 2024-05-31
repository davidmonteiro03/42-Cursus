/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrinptrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:22:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/05 22:39:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

bool	ft_ptrinptrs(t_list *set, char *target)
{
	char	*tmp;

	while (set != NULL)
	{
		tmp = (char *)set->content;
		if (tmp == target)
			return (true);
		set = set->next;
	}
	return (false);
}
