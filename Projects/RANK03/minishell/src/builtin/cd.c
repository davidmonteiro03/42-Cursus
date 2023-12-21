/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:35:51 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_pwd(t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = getcwd(NULL, 0);
	if (retpwd(mini))
		tmp = ft_strdup(retpwd(mini));
	if (tmp2 && check_env(mini, tmp2, ft_strdup("PWD")))
	{
		if (!check_exp(mini, ft_strdup("PWD")))
			add_env(mini, ft_strdup("PWD"), getcwd(NULL, 0));
		ft_del_exp(&mini->exp, "PWD");
		if (retoldpwd(mini))
		{
			ft_del_env(&mini->env, "OLDPWD");
			ft_del_exp(&mini->exp, "OLDPWD");
			add_exp(mini, ft_strdup("OLDPWD"));
		}
	}
	else
	{
		if (check_env(mini, ft_strdup(tmp), ft_strdup("OLDPWD")))
			add_env(mini, ft_strdup("OLDPWD"), tmp);
		else
			free(tmp);
	}
}

static void	cd_enter(void)
{
	t_mini	*mini;
	char	*tmp;

	mini = get_mini(NULL);
	tmp = expand(ft_strdup("$HOME"));
	if (chdir(tmp) != 0)
		cd_err(tmp);
	else
		update_pwd(mini);
	free(tmp);
}

static void	change_path(void)
{
	t_mini	*mini;
	char	*path;
	char	*tmp;

	mini = get_mini(NULL);
	path = ft_strdup(mini->input->command->args[0]);
	if (!ft_strncmp(path, "~", 1))
	{
		tmp = path;
		path = ft_joint_free(expand(ft_strdup("$HOME")),
				ft_strdup(path + 1));
		free(tmp);
	}
	else if (!ft_strncmp(path, "-", 1))
	{
		tmp = path;
		path = ft_joint_free(expand(ft_strdup("$OLDPWD")),
				ft_strdup(path + 1));
		free(tmp);
	}
	if (chdir(path) != 0)
		cd_err(path);
	else
		update_pwd(mini);
	free(path);
}

int	ft_cd(void)
{
	t_mini	*mini;

	mini = get_mini(NULL);
	get_exit_code(0, 1);
	if (!mini->input->command->args)
		cd_enter();
	else if (mini->input->command->args[1])
	{
		ft_fprintf(2, "bash: cd: too many arguments\n");
		get_exit_code(1, 1);
	}
	else
		change_path();
	return (0);
}
