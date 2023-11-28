/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:17:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 08:23:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_2.h"

int	main(int ac, char **av, char **env)
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
	g->v = env;
	return (multiple_free("%a%a", g->l, g), (void)ac, (void)av, 0);
}
