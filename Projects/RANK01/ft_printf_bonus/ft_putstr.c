/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:06:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 15:07:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_help *help)
{
	if (help == NULL)
		return ;
	if (str == NULL)
		help->len += write(help->fd, "(null)", 6);
	else
		while (*str != '\0')
			ft_putchar(*str++, help);
}
