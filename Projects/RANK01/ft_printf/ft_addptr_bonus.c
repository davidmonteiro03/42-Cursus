/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:06:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:06:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addptr_bonus(void *ptr, t_list **list)
{
	char	*str;

	str = ft_converthex((size_t)ptr, ft_len((size_t)ptr));
	if (!str)
		return ;
	return (ft_addstr_bonus(str, list), free(str));
}
