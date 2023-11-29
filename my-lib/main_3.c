/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:17:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/29 11:02:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_3.h"

int	wild_match(char *path, char *ptrn)
{
	if (!*path && !*ptrn)
		return (TRUE);
	if (*path == '*' && *(path + 1) && !*ptrn)
		return (FALSE);
	if (*path == '?' || *path == *ptrn)
		return (wild_match(path + 1, ptrn + 1));
	if (*path == '*')
		return (wild_match(path + 1, ptrn) || wild_match(path, ptrn + 1));
	return (FALSE);
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
					wild_match(as[i], gb->pt->d_name))
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
	gb->ai = 0;
	wild_prep(gb, gb->as, 0, -1);
	gb->ag = (char **)malloc(sizeof(char *) * (gb->ai + 1));
	gb->ag[gb->ai] = NULL;
	gb->ai = 0;
	wild_prep(gb, gb->as, 1, -1);
}

int	main(int ac, char **av, char **env)
{
	t_gb	*gb;

	gb = (t_gb *)malloc(sizeof(t_gb));
	if (!gb)
		return (0);
	gb->ln = readline("wildcard $ ");
	if (!gb->ln)
		return (send_to_trash(gb), 0);
	if (!*gb->ln)
		return (send_to_trash(gb), 0);
	gb->as = ft_split(gb->ln, ' ');
	if (!gb->as)
		return (send_to_trash(gb), 0);
	gb->cm = buildfree(ft_strdup("/bin/"), ft_strdup(gb->as[0]), &ft_strjoin);
	if (!gb->cm)
		return (send_to_trash(gb), 0);
	wild_get(gb);
	if (!fork())
		execve(gb->cm, gb->ag, env);
	else
		wait(NULL);
	return ((void)ac, (void)av, send_to_trash(gb), 0);
}
