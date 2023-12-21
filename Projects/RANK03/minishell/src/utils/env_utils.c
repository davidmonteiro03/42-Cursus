/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:28:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_env(t_mini *mini, char *key, char *value)
{
	t_env	*env;
	t_exp	*tmp;

	tmp = mini->exp;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, key))
		{
			ft_del_exp(&mini->exp, key);
			break ;
		}
		tmp = tmp->next;
	}
	if (!check_env(mini, ft_strdup(value), ft_strdup(key)))
		return (free(key), free(value));
	env = malloc(sizeof(t_env));
	env->key = key;
	env->value = value;
	env->next = NULL;
	if (mini->env)
		env->next = mini->env;
	mini->env = env;
}

int	list_len_env(t_env *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void	print_env(t_mini *mini)
{
	char	*str;
	t_env	*env;

	env = mini->env;
	while (env)
	{
		if (env->value)
		{
			str = struct_to_str_env(env->key, env->value);
			ft_fprintf(1, "%s\n", str);
			free(str);
		}
		env = env->next;
	}
}
