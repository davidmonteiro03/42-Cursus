/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:53:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_env(t_mini *mini, char *str, char *check)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, check))
		{
			if (tmp->value && str)
			{
				free(tmp->value);
				tmp->value = str;
			}
			return (free(check), 0);
		}
		tmp = tmp->next;
	}
	return (free(check), free(str), 1);
}

int	check_exp(t_mini *mini, char *check)
{
	t_exp	*tmp;

	tmp = mini->exp;
	while (tmp)
	{
		if (tmp->key && ! ft_strcmp(tmp->key, check))
			return (free(check), 0);
		tmp = tmp->next;
	}
	return (free(check), 1);
}
