/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:19:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 22:56:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

void	chk(t_gb *gb, int mode, char *str)
{
	if (mode)
		gb->ag[gb->ai++] = ft_strdup(str);
	else
		gb->ai++;
}

int	chk_wild(t_gb *gb, char *str, int mode)
{
	if (gb->pt->d_name[0] != '.' && \
		!stat(gb->pt->d_name, &gb->st) && \
		wildcmp(gb->pt->d_name, str))
		return (chk(gb, mode, gb->pt->d_name), 1);
	return (0);
}

void	wild_prep(t_gb *gb, char **as, int mode, int i)
{
	gb->ai = 0;
	while (as[++i])
	{
		gb->dr = opendir(".");
		if (!gb->dr)
			return ;
		gb->fg = 0;
		while (1)
		{
			gb->pt = readdir(gb->dr);
			if (!gb->pt)
				break ;
			if (chk_wild(gb, as[i], mode))
				gb->fg++;
		}
		if (!gb->fg)
			chk(gb, mode, as[i]);
		if (mode)
			gb->tb[i] = gb->ai;
		closedir(gb->dr);
	}
}

void	wild_get(t_gb *gb)
{
	wild_prep(gb, gb->as, 0, -1);
	gb->ag = (char **)malloc(sizeof(char *) * (gb->ai + 1));
	gb->ag[gb->ai] = NULL;
	gb->tb = (int *)malloc(sizeof(int) * (dsp_sz(gb->as, -1, FALSE)));
	wild_prep(gb, gb->as, 1, -1);
}
