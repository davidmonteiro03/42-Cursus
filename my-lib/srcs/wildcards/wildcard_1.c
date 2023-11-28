/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:14:36 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 07:18:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/my_lib.h"

int	wildcard_prep(t_g *g, int i)
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
			!S_ISDIR(st.st_mode))
			i++;
	}
	return (closedir(g->ptr->d), free(g->ptr), i);
}

void	wildcard_exec(t_g *g, int i)
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
			!S_ISDIR(st.st_mode))
			g->a[i++] = ft_strdup(g->ptr->e->d_name);
	}
	return (closedir(g->ptr->d), free(g->ptr));
}

void	sort_and_dsp(char **a, int i)
{
	int	j;

	while (a[++i])
	{
		j = i;
		while (a[++j])
			if (ft_strncmp(a[i], a[j], ft_strlen(a[i])) > 0)
				ft_swap_str(&a[i], &a[j]);
		if (i > 0)
			printf("  ");
		printf("%s", a[i]);
	}
	printf("\n");
}

void	ft_wild_1(t_g *g)
{
	g->len = wildcard_prep(g, 0);
	g->a = (char **)malloc(sizeof(char *) * (g->len + 1));
	g->a[g->len] = NULL;
	wildcard_exec(g, 0);
	sort_and_dsp(g->a, -1);
	multiple_free("%b", g->a);
}
