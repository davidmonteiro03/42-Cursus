/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:45:09 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	display_minus(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while (str[tmp->i + j] && ft_isdigit(str[tmp->i + j]) != 1
		&& str[tmp->i + j] != '.' && ft_isalpha(str[tmp->i + j]) != 1)
	{
		if (str[tmp->i + j] == '-')
			return (1);
		j++;
	}
	return (0);
}

int	display_plus(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while (ft_isalpha(str[tmp->i + j]) != 1 && str[tmp->i + j] != '.'
		&& ft_isdigit(str[tmp->i + j]) != 1 && str[tmp->i + j])
	{
		if (str[tmp->i + j] == '+')
			return (1);
		j++;
	}
	return (0);
}

int	display_sharp(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while (ft_isalpha(str[tmp->i + j]) != 1 && str[tmp->i + j] != '.'
		&& ft_isdigit(str[tmp->i + j]) != 1 && str[tmp->i + j])
	{
		if (str[tmp->i + j] == '#')
			return (1);
		j++;
	}
	return (0);
}

int	display_space(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while ((ft_isalpha(str[tmp->i + j]) != 1 && str[tmp->i + j] != '.'
			&& ft_isdigit(str[tmp->i + j]) != 1) && str[tmp->i + j])
	{
		if (str[tmp->i + j] == ' ')
			return (1);
		j++;
	}
	return (0);
}

int	display_zero(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while ((ft_isalpha(str[tmp->i + j]) != 1 && str[tmp->i + j] != '.'
			&& ft_isdigit(str[tmp->i + j - 1]) != 1) && str[tmp->i + j])
	{
		if (str[tmp->i + j] == '0')
			return (1);
		j++;
	}
	return (0);
}
