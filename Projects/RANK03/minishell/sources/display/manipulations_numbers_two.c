/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_numbers_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:24:14 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	display_digits(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while (str[tmp->i + j] != '\0')
	{
		if (ft_isdigit(str[tmp->i + j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	display_figures(int *d)
{
	int	f;
	int	k;

	k = *d;
	f = 1;
	while (k-- > 1)
		f = f * 10;
	return (f);
}

int	display_nbrlen(unsigned long long int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	display_nbrlen_ten(int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	display_nbrlen_unsigned(unsigned int nbr, int base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
