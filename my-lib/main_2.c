/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:17:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 14:22:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_2.h"

static void	ft_trash(t_g *g)
{
	if (!g)
		return ;
	if (g->l)
		free(g->l);
	free(g);
}

int	main(void)
{
	t_g	*g;

	g = (t_g *)malloc(sizeof(t_g));
	if (!g)
		return (0);
	g->l = readline("wildcard (parser) $ ");
	g->l = buildfree(g->l, ft_strdup(" "), &ft_strtrim);
	if
	return (ft_trash(g), 0);
}
