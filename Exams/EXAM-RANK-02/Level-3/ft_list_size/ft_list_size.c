/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:22:10 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/12 21:06:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list)
	{
		++len;
		begin_list = begin_list->next;
	}
	return (len);
}
