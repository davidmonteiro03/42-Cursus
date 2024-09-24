/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:45:09 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_minus(const char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i + j] && ft_isdigit(str[*i + j]) != 1
		&& str[*i + j] != '.' && ft_isalpha(str[*i + j]) != 1)
	{
		if (str[*i + j] == '-')
			return (1);
		j++;
	}
	return (0);
}

int	ft_space(const char *str, int *i)
{
	int	j;

	j = 0;
	while ((ft_isalpha(str[*i + j]) != 1 && str[*i + j] != '.'
			&& ft_isdigit(str[*i + j]) != 1) && str[*i + j])
	{
		if (str[*i + j] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int	ft_plus(const char *str, int *i)
{
	int	j;

	j = 0;
	while (ft_isalpha(str[*i + j]) != 1 && str[*i + j] != '.'
		&& ft_isdigit(str[*i + j]) != 1 && str[*i + j])
	{
		if (str[*i + j] == '+')
			return (1);
		j++;
	}
	return (0);
}

int	ft_sharp(const char *str, int *i)
{
	int	j;

	j = 0;
	while (ft_isalpha(str[*i + j]) != 1 && str[*i + j] != '.'
		&& ft_isdigit(str[*i + j]) != 1 && str[*i + j])
	{
		if (str[*i + j] == '#')
			return (1);
		j++;
	}
	return (0);
}

int	ft_zero(const char *str, int *i)
{
	int	j;

	j = 0;
	while ((ft_isalpha(str[*i + j]) != 1 && str[*i + j] != '.'
			&& ft_isdigit(str[*i + j - 1]) != 1) && str[*i + j])
	{
		if (str[*i + j] == '0')
			return (1);
		j++;
	}
	return (0);
}
