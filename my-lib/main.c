/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:24:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 19:42:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	wildcard_prep(t_g *g, int i)
{
	g->d = opendir(".");
	if (!g->d)
		return (0);
	while (1)
	{
		g->e = readdir(g->d);
		if (!g->e)
			break ;
		if (!stat(g->e->d_name, &g->st) && !S_ISDIR(g->st.st_mode))
			i++;
	}
	closedir(g->d);
	return (i);
}

void	wildcard_exec(t_g *g, int i)
{
	g->d = opendir(".");
	if (!g->d)
		return ;
	while (1)
	{
		g->e = readdir(g->d);
		if (!g->e)
			break ;
		if (!stat(g->e->d_name, &g->st) && !S_ISDIR(g->st.st_mode))
			g->a[i++] = ft_strdup(g->e->d_name);
	}
	closedir(g->d);
}

char	*ft_strlow(char *s)
{
	int		i;
	char	*ret;

	i = -1;
	ret = ft_strdup(s);
	while (ret[++i])
		ret[i] = ft_tolower(ret[i]);
	return (ret);
}

void	ft_swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_and_dsp(char **a, int i)
{
	char	*c;
	char	*n;
	int		j;

	while (a[++i])
	{
		j = i;
		while (a[++j])
		{
			c = ft_strlow(a[i]);
			n = ft_strlow(a[j]);
			if (ft_strncmp(c, n, ft_strlen(c)) > 0)
				ft_swap_str(&a[i], &a[j]);
			multiple_free("%a%a", c, n);
		}
		if (i > 0)
			printf("  ");
		printf("%s", a[i]);
	}
}

int	main(int ac, char **av, char **env)
{
	t_g		*g;

	g = (t_g *)malloc(sizeof(t_g));
	g->v = env;
	g->l = readline("wildcard $ ");
	g->l = buildfree(g->l, ft_strdup(" "), &ft_strtrim);
	if (g->l[0] == '\"')
		g->l = buildfree(g->l, ft_strdup("\""), &ft_strtrim);
	else if (g->l[0] == '\'')
		g->l = buildfree(g->l, ft_strdup("\'"), &ft_strtrim);
	if (!ft_strncmp(g->l, "*", ft_strlen(g->l)))
	{
		g->len = wildcard_prep(g, 0);
		g->a = (char **)malloc(sizeof(char *) * (g->len + 1));
		g->a[g->len] = NULL;
		wildcard_exec(g, 0);
		sort_and_dsp(g->a, -1);
	}
	multiple_free("%b%a%a", g->a, g->l, g);
	return ((void)ac, (void)av, (void)env, 0);
}
