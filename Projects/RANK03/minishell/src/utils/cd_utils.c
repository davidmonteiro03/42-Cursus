/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:54:22 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*retpwd(t_mini *mini)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp != NULL)
	{
		if (tmp->key && !ft_strcmp(tmp->key, "PWD")
			&& tmp->value != NULL)
			return (tmp->value);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

char	*retoldpwd(t_mini *mini)
{
	t_env	*tmp;
	t_exp	*tmp2;

	tmp = mini->env;
	tmp2 = mini->exp;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, "OLDPWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		if (tmp2->key && !ft_strcmp(tmp2->key, "OLDPWD"))
			return (tmp2->key);
		tmp2 = tmp2->next;
	}
	return (NULL);
}
