/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:24:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 23:03:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib.h"

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
		ft_wild_1(g);
		ft_wild_2(g);
	}
	multiple_free("%a%a", g->l, g);
	return ((void)ac, (void)av, (void)env, 0);
}
