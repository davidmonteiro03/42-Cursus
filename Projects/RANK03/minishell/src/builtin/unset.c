/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:31:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_del_env(t_env **lst, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, key))
		{
			if (prev)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_del_exp(t_exp **lst, char *key)
{
	t_exp	*tmp;
	t_exp	*prev;

	tmp = *lst;
	prev = NULL;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, key))
		{
			if (prev)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			free(tmp->key);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int	unset_arg(char *key, t_env **env, t_exp **exp)
{
	t_env	*tmp_env;
	t_exp	*tmp_exp;

	tmp_env = *env;
	tmp_exp = *exp;
	if (!key)
		return (0);
	while (tmp_env)
	{
		if (!tmp_env->key)
			break ;
		if (!ft_strcmp(tmp_env->key, key))
			return (ft_del_env(env, key), 0);
		tmp_env = tmp_env->next;
	}
	while (tmp_exp)
	{
		if (!tmp_exp->key)
			break ;
		if (!ft_strcmp(tmp_exp->key, key))
			return (ft_del_exp(exp, key), 0);
		tmp_exp = tmp_exp->next;
	}
	return (0);
}

int	check_if_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (1);
	while (str[i])
	{
		if (str[i] == '!' || str[i] == '@' || str[i] == '#'
			|| str[i] == '$' || str[i] == '%' || str[i] == '^'
			|| str[i] == '&' || str[i] == '*' || str[i] == '('
			|| str[i] == ')' || str[i] == '-' || str[i] == '+'
			|| str[i] == '{' || str[i] == '}' || str[i] == '['
			|| str[i] == ']' || str[i] == '|' || str[i] == '\\'
			|| str[i] == ';' || str[i] == ':' || str[i] == '\''
			|| str[i] == '"' || str[i] == '<' || str[i] == '>'
			|| str[i] == ',' || str[i] == '.' || str[i] == '/'
			|| str[i] == '?' || str[i] == '=' || str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(char **args, t_env **env, t_exp **exp)
{
	int		i;

	i = 0;
	if (!args)
		return (1);
	if (check_options(args, "unset"))
		return (get_exit_code(2, 1), 1);
	while (args[i])
	{
		if (check_if_digit(args[i]) == 0)
			unset_arg(args[i], env, exp);
		else
			printf("bash: unset: \'%s \': not a valid identifier\n", args[i]);
		i++;
	}
	return (0);
}
