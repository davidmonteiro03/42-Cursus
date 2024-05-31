/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:45:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 08:24:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_parse_bonus(char **argv, bool *has_flag)
{
	char	**tmp;
	int		i;
	bool	flag;

	flag = true;
	tmp = ft_acumulate(argv);
	if (tmp == NULL)
		ft_error();
	i = -1;
	while (tmp[++i])
	{
		if (ft_strcmp(tmp[i], "-d") == 0)
		{
			if (*has_flag == true || i != 0)
				flag = false;
			*has_flag = true;
			continue ;
		}
		ft_check(tmp[i], &flag);
		if (flag == false)
			break ;
	}
	free_strs(tmp);
	if (flag == false)
		ft_error();
}
