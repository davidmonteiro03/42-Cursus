/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparenums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:36:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:47:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	int		i;
	long	num;

	sign = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (!nptr[i])
		return (-2147483649);
	num = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	if (nptr[i])
		return (-2147483649);
	return (num * sign);
}

int	findrep(int *tab, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (i != j && tab[i] == tab[j])
				return (1);
	}
	return (0);
}

int	*validnums(char **strs)
{
	int	i;
	int	*tab;
	int	len;

	len = 0;
	while (strs[len])
	{
		if (ft_atol(strs[len]) < -2147483648 || ft_atol(strs[len]) > 2147483647)
			errorargs(strs);
		len++;
	}
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		errorargs(strs);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_atoi(strs[i]);
		i++;
	}
	if (findrep(tab, len) == 1)
		errorall(tab, strs);
	return (tab);
}
