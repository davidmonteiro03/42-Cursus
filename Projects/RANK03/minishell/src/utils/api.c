/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:49:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exp	*get_exp(t_exp *exp)
{
	static t_exp	*data;

	if (exp)
		data = exp;
	return (data);
}

t_env	*get_env(t_env *env)
{
	static t_env	*data;

	if (env)
		data = env;
	return (data);
}

int	get_exit_code(int code, int change)
{
	static int	exit_code;

	if (change)
		exit_code = code;
	return (exit_code);
}

t_mini	*get_mini(t_mini *mini)
{
	static t_mini	*data;

	if (mini)
		data = mini;
	return (data);
}
