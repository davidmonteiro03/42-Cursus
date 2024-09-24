/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_numbers_two_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:24:14 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen_unsigned(unsigned int nbr, int base)
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

int	ft_nbrlen_ten(int nbr, int base)
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

int	ft_nbrlen(unsigned long long int nbr, int base)
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

int	ft_figures(int *d)
{
	int	f;
	int	k;

	k = *d;
	f = 1;
	while (k-- > 1)
		f = f * 10;
	return (f);
}

int	ft_digits(const char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i + j] != '\0')
	{
		if (ft_isdigit(str[*i + j]) == 1)
			return (1);
		j++;
	}
	return (0);
}
