/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:16:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*verify_helper(char *cmd, char *env_path)
{
	char	*token;
	char	*check;
	char	*path;

	token = ft_strtok(env_path, ":");
	while (token)
	{
		path = ft_strjoin(token, "/");
		check = ft_strjoin(path, cmd);
		free(path);
		if (access(check, F_OK) == 0)
			return (free(env_path), check);
		free(check);
		token = ft_strtok(NULL, ":");
	}
	free(env_path);
	return (cmd);
}

char	*verify_access(char *cmd)
{
	t_mini	*mini;
	t_env	*tmp;

	mini = get_mini(NULL);
	if (cmd[0] == '/')
		return (cmd);
	tmp = mini->env;
	while (tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->next;
	if (!tmp)
		return (cmd);
	cmd = verify_helper(cmd, ft_strdup(tmp->value));
	return (cmd);
}
