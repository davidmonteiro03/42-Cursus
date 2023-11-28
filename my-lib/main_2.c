/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:17:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 08:41:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_2.h"

void	simple(char *l, char **e)
{
	char	**t;
	char	*c;

	t = ft_split(l, ' ');
	c = ft_strdup("/bin/");
	c = buildfree(c, ft_strdup(t[0]), &ft_strjoin);
	if (!fork())
		execve(c, t, e);
	else
		wait(NULL);
	multiple_free("%a%b", c, t);
}

int	main(int c, char **v, char **e)
{
	t_g	*g;

	g = (t_g *)malloc(sizeof(t_g));
	if (!g)
		return (1);
	g->l = readline("wildcard (pro) $ ");
	if (!g->l)
		return (free(g), 0);
	if (!*g->l)
		return (free(g->l), free(g), 0);
	g->l = buildfree(g->l, ft_strdup(" "), &ft_strtrim);
	if (!ft_strchr(g->l, '*'))
		return (simple(g->l, e), free(g->l), free(g), 0);
	g->t = ft_split(g->l, '*');
	multiple_free("%b", g->t);
	return (multiple_free("%a%a", g->l, g), (void)c, (void)v, 0);
}
