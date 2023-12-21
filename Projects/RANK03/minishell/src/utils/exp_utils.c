/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:29:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_exp(t_mini *mini, char *key)
{
	t_exp	*exp;
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, key))
		{
			ft_del_env(&mini->env, key);
			break ;
		}
		tmp = tmp->next;
	}
	if (!check_exp(mini, ft_strdup(key)))
		return (free(key));
	exp = malloc(sizeof(t_exp));
	exp->key = key;
	if (!mini->exp)
	{
		exp->next = NULL;
		mini->exp = exp;
		return ;
	}
	exp->next = mini->exp;
	mini->exp = exp;
}

int	list_len_exp(t_exp *list)
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

static void	sort_exp(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static char	**list_to_array(t_mini *mini)
{
	char	**array;
	t_exp	*exp;
	t_env	*env;

	array = malloc(sizeof(char *)
			* (list_len_exp(mini->exp) + list_len_env(mini->env) + 1));
	auto int i = 0;
	exp = mini->exp;
	env = mini->env;
	while (exp && exp->key)
	{
		array[i++] = struct_to_str(exp->key, NULL);
		exp = exp->next;
	}
	while (env && env->key)
	{
		array[i++] = struct_to_str(env->key, env->value);
		env = env->next;
	}
	array[i] = NULL;
	sort_exp(array);
	return (array);
}

void	print_export(t_mini *mini)
{
	char	**exp;
	int		i;

	i = 0;
	exp = list_to_array(mini);
	while (exp[i])
	{
		ft_fprintf(1, "declare -x %s\n", exp[i]);
		free(exp[i]);
		i++;
	}
	free(exp);
}
