/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 16:10:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_mini	*mini;

	(void)av;
	if (ac != 1)
		usage();
	mini = init_mini(env);
	if (!mini)
		error();
	while (exec_mini(mini) == 0)
	{
	}
	exit_mini(mini, 0);
	return (0);
}
