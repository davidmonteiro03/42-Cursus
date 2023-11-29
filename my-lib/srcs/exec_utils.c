/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:19:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/29 13:43:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

int	wildcmp(const char *path, const char *ptrn)
{
	if (!*ptrn)
		return (!*path);
	if (*ptrn == '*')
	{
		while (*path)
		{
			if (wildcmp(path, ptrn + 1))
				return (1);
			path++;
		}
		return (wildcmp(path, ptrn + 1));
	}
	if (*ptrn == '?' || *path == *ptrn)
		return (wildcmp(path + 1, ptrn + 1));
	return (0);
}

void	chk(t_gb *gb, int mode, char *str)
{
	if (mode)
		gb->ag[gb->ai++] = ft_strdup(str);
	else
		gb->ai++;
}

void	wild_prep(t_gb *gb, char **as, int mode, int i)
{
	gb->ai = 0;
	while (as[++i])
	{
		gb->dr = opendir(".");
		if (!gb->dr)
			return ;
		if (ft_strchr(as[i], '*') || ft_strchr(as[i], '?'))
		{
			while (1)
			{
				gb->pt = readdir(gb->dr);
				if (!gb->pt)
					break ;
				if (gb->pt->d_name[0] != '.' && \
					!stat(gb->pt->d_name, &gb->st) && \
					wildcmp(gb->pt->d_name, as[i]))
					chk(gb, mode, gb->pt->d_name);
			}
		}
		else
			chk(gb, mode, as[i]);
		closedir(gb->dr);
	}
}

void	wild_get(t_gb *gb)
{
	wild_prep(gb, gb->as, 0, -1);
	gb->ag = (char **)malloc(sizeof(char *) * (gb->ai + 1));
	gb->ag[gb->ai] = NULL;
	wild_prep(gb, gb->as, 1, -1);
}
