/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib_5.h"

void	special_print(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			while (str[++i] && str[i] != '\"')
				printf("%c", str[i]);
			printf(" => EXPAND\n");
			continue ;
		}
		if (str[i] == '\'')
		{
			while (str[++i] && str[i] != '\'')
				printf("%c", str[i]);
			printf(" => NO EXPAND\n");
			continue ;
		}
		printf("%c", str[i]);
	}
}

void	print_strs(char **strs, int i, char *sep)
{
	while (strs[++i])
	{
		special_print(strs[i]);
		if (strs[i + 1])
			printf("%s", sep);
	}
}
