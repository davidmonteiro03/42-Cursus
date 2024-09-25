/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:58:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 10:31:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fillvariables(t_env *env, char *const *envp,
		void (*insert)(t_vars **, t_vars *))
{
	t_vars	*node;
	size_t	i;

	if (env == NULL || envp == NULL || insert == NULL)
		return ;
	i = 0;
	while (envp[i] != NULL)
	{
		node = vars_new(envp[i]);
		if (node == NULL)
			return (vars_clear(&env->envs));
		if (utils_strcmp(node->key, "_") != 0)
			insert(&env->envs, node);
		else
			vars_clear(&node);
		++i;
	}
}

static int	resetshlvl(int high_value)
{
	char	*output;
	char	*tmp;

	tmp = ft_itoa(high_value);
	output = ft_strjoin(NAME ": warning: shell level (", tmp);
	output = utils_joinfree(output, ft_strdup(") too high, resetting to 1\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
	return (1);
}

static void	handleshlvl(t_env *env, void (*insert)(t_vars **, t_vars *))
{
	char	*shlvl_str;
	char	*shlvl_value;
	int		shlvl_num;

	if (env == NULL || insert == NULL)
		return ;
	shlvl_str = vars_getvalue(env, "SHLVL");
	if (shlvl_str == NULL)
		vars_export(&env->envs, (t_exp){.key = "SHLVL", .op = "=",
			.value = "1"}, insert);
	else
	{
		shlvl_num = utils_shellatoi(shlvl_str) + 1;
		if (shlvl_num >= SHLVL_MAX)
			shlvl_num = resetshlvl(shlvl_num);
		else if (shlvl_num < 0)
			shlvl_num = 0;
		shlvl_value = ft_itoa(shlvl_num);
		vars_export(&env->envs, (t_exp){.key = "SHLVL", .op = "=",
			.value = shlvl_value}, insert);
		if (shlvl_value != NULL)
			free(shlvl_value);
	}
}

void	env_init(t_env *env, char *const *envp, void (*insert)(t_vars **,
			t_vars *))
{
	if (env == NULL)
		return ;
	env->envs = NULL;
	env->exps = NULL;
	env->envp = NULL;
	env->underscore = ft_strdup("]");
	if (envp == NULL || insert == NULL)
		return ;
	fillvariables(env, envp, insert);
	handleshlvl(env, insert);
	if (env->envs == NULL)
		return ;
	env->exps = vars_copy(env->envs, insert);
	env->envp = utils_listtoarray(env->envs);
}
