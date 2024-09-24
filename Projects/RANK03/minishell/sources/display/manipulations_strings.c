/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:36:24 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_putstr_len(char *c, t_tmp *tmp, int *size)
{
	int	i;
	int	g;

	i = 0;
	g = *size;
	while (g-- > 0)
		display_putchar_len(c[i++], tmp);
}

void	display_putstr_lennil(t_tmp *tmp)
{
	write(tmp->fd, "(nil)", 5);
	tmp->len += 5;
}

void	display_putstr_lennull(t_tmp *tmp)
{
	write(tmp->fd, "(null)", 6);
	(tmp->len) += 6;
}

void	display_putstr_lenspaces(t_tmp *tmp, int *strsize, int *printsize)
{
	while ((*printsize) > *strsize)
	{
		display_putchar_len(' ', tmp);
		(*printsize)--;
	}
}

void	display_putstr_lenszeros(t_tmp *tmp, int *strsize, int *printsize)
{
	int	i;

	i = *printsize;
	while (i > *strsize)
	{
		display_putchar_len('0', tmp);
		i--;
	}
}
