/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:11:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 13:33:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cmd404(char *const path)
{
	char	*output;

	if (path == NULL)
		return ;
	g_exit_status = 127;
	output = ft_strjoin(path, ": ");
	output = utils_joinfree(output, ft_strdup("command not found\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
}

static char	*verifypath(char *const route, char *const path)
{
	char	*file;

	if (route == NULL || path == NULL)
		return (NULL);
	file = route;
	if (*file == '\0')
		file = utils_joinfree(file, ft_strdup("."));
	file = utils_joinfree(file, ft_strdup("/"));
	file = utils_joinfree(file, ft_strdup(path));
	if (access(file, F_OK) == 0)
		return (file);
	return (free(file), NULL);
}

static char	*helppath(char *const env_path, char *const path)
{
	char	*ret;
	size_t	i;
	size_t	k;

	if (env_path == NULL || path == NULL)
		return (NULL);
	ret = NULL;
	if (*env_path == '\0')
		ret = verifypath(ft_strdup("."), path);
	i = 0;
	while (env_path[i] != '\0')
	{
		k = i;
		while (env_path[i] != '\0' && env_path[i] != ':')
			i++;
		ret = verifypath(ft_substr(env_path, k, i - k), path);
		if (ret == NULL && env_path[i] == ':')
			if (env_path[++i] == '\0')
				ret = verifypath(ft_strdup("."), path);
		if (ret != NULL)
			return (ret);
	}
	if (ret != NULL)
		return (ret);
	return (cmd404(path), NULL);
}

char	*builtins_getpath(char *const path, t_env *env)
{
	char	*env_path;

	if (path == NULL)
		return (NULL);
	if (*path == '\0')
		return (cmd404(path), NULL);
	if (ft_strchr(path, '/') != NULL)
		return (ft_strdup(path));
	env_path = vars_getvalue(env, "PATH");
	if (env_path == NULL)
		return (ft_strdup(path));
	return (helppath(env_path, path));
}
