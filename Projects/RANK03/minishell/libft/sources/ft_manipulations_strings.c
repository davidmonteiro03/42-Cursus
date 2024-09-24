/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_strings_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:36:24 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_lennil(int *len)
{
	write(1, "(nil)", 5);
	*len += 5;
}

void	ft_putstr_lenszeros(int *len, int *strsize, int *printsize)
{
	int	i;

	i = *printsize;
	while (i > *strsize)
	{
		ft_putchar_len('0', len);
		i--;
	}
}

void	ft_putstr_lenspaces(int *len, int *strsize, int *printsize)
{
	while ((*printsize) > *strsize)
	{
		ft_putchar_len(' ', len);
		(*printsize)--;
	}
}

void	ft_putstr_len(char *c, int *len, int *size)
{
	int	i;
	int	g;

	i = 0;
	g = *size;
	while (g-- > 0)
		ft_putchar_len(c[i++], len);
}

void	ft_putstr_lennull(int *len)
{
	write(1, "(null)", 6);
	(*len) += 6;
}
