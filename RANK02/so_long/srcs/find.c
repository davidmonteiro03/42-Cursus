/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:42:09 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 11:53:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_invalid_char(char *str, t_chars chars)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != chars.empty && str[i] != chars.wall && \
			str[i] != chars.collect && str[i] != chars.exit && \
			str[i] != chars.start_pos)
			return (1);
	return (0);
}
