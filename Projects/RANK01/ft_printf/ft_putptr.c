/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:54:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:54:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *len)
{
	char	*str;

	str = ft_converthex((size_t)ptr, ft_len((size_t)ptr));
	if (!str)
		return ;
	return (ft_putstr(str, len), free(str));
}
