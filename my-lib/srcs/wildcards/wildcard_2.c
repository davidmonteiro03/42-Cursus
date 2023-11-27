/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:17:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 23:29:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/my_lib.h"

int	wildcard_prep_2(t_g *g, int i)
{
	struct stat	st;

	g->ptr = (t_d *)malloc(sizeof(t_d));
	g->ptr->d = opendir(".");
	if (!g->ptr->d)
		return (free(g->ptr), 0);
	while (1)
	{
		g->ptr->e = readdir(g->ptr->d);
		if (!g->ptr->e)
			break ;
		if (g->ptr->e->d_name[0] != '.' && !stat(g->ptr->e->d_name, &st) && \
			S_ISDIR(st.st_mode))
			i++;
	}
	return (closedir(g->ptr->d), free(g->ptr), i);
}

void	wildcard_exec_2(t_g *g, int i)
{
	struct stat	st;

	g->ptr = (t_d *)malloc(sizeof(t_d));
	g->ptr->d = opendir(".");
	if (!g->ptr->d)
		return (free(g->ptr));
	while (1)
	{
		g->ptr->e = readdir(g->ptr->d);
		if (!g->ptr->e)
			break ;
		if (g->ptr->e->d_name[0] != '.' && !stat(g->ptr->e->d_name, &st) && \
			S_ISDIR(st.st_mode))
			g->d[i++] = ft_strdup(g->ptr->e->d_name);
	}
	return (closedir(g->ptr->d), free(g->ptr));
}

void	sort_strs(t_g *g, int i)
{
	int	j;

	while (g->d[++i])
	{
		j = i;
		while (g->d[++j])
			if (ft_strncmp(g->d[i], g->d[j], ft_strlen(g->d[i])) > 0)
				ft_swap_str(&g->d[i], &g->d[j]);
	}
}

void	dsp_each_dir(t_g *g, int i)
{
	char	**args;

	args = NULL;
	while (g->d[++i])
	{
		chdir(g->d[i]);
		printf("\n%s:\n", g->d[i]);
		if (!fork())
			execve("/bin/ls", args, g->v);
		else
			wait(NULL);
		chdir("..");
	}
}

void	ft_wild_2(t_g *g)
{
	g->l_n = wildcard_prep_2(g, 0);
	g->d = (char **)malloc(sizeof(char *) * (g->l_n + 1));
	g->d[g->l_n] = NULL;
	wildcard_exec_2(g, 0);
	sort_strs(g, -1);
	dsp_each_dir(g, -1);
	multiple_free("%b", g->d);
}
