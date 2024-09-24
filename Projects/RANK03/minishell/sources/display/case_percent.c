/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 04:46:10 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_case_percent(const char *str, t_tmp *tmp)
{
	while (str[tmp->i + 1] != '%')
		(tmp->i)++;
	if (str[tmp->i + 1] != '\0' && str[tmp->i + 1] == '%')
	{
		display_putchar_len(str[tmp->i + 1], tmp);
		(tmp->i)++;
	}
}
