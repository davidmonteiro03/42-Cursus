/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:41:31 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 10:35:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	utils_shellatoi(char *const str)
{
	size_t	i;
	int		sign;
	int		num;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && utils_isspace(str[i]) != 0)
		i++;
	if (str[i] == '\0')
		return (0);
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] == '\0')
		return (0);
	num = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
		num = num * 10 + str[i++] - '0';
	while (str[i] != '\0' && utils_isspace(str[i]) != 0)
		i++;
	if (str[i] != '\0')
		return (0);
	return (num * sign);
}
