/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:23:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 19:31:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dir	*get_dir(t_mini *mini)
{
	t_dir	*dir;

	dir = (t_dir *)malloc(sizeof(t_dir));
	if (!dir)
		return (NULL);
	dir->type = false;
	dir->name = mini->pwd;
	if (ft_strnstr(mini->pwd, mini->home, ft_strlen(mini->home)))
	{
		dir->type = true;
		dir->name = ft_substr(mini->pwd, ft_strlen(mini->home), \
			ft_strlen(mini->pwd) - ft_strlen(mini->home));
	}
	return (dir);
}

t_mini	*init_mini(char **env)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = env;
	mini->home = getenv("HOME");
	mini->pwd = getenv("PWD");
	mini->dir = get_dir(mini);
	if (!mini->dir)
		return (free(mini), NULL);
	mini->size = 0;
	mini->args = NULL;
	mini->command = NULL;
	return (mini);
}
