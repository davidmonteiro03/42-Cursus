/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_percent_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 04:46:10 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_case_percent(const char *str, int *i, int *len)
{
	while (str[*i + 1] != '%')
		(*i)++;
	if (str[*i + 1] != '\0' && str[*i + 1] == '%')
	{
		ft_putchar_len(str[*i + 1], len);
		(*i)++;
	}
}
