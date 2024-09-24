/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:25:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/16 14:09:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	errorfile(char *const name, char *const error)
{
	char	*output;

	output = ft_strjoin(NAME ": ", name);
	output = utils_joinfree(output, ft_strdup(": "));
	output = utils_joinfree(output, ft_strdup(error));
	output = utils_joinfree(output, ft_strdup("\n"));
	write(STDERR_FILENO, output, ft_strlen(output));
	free(output);
	return (EXIT_FAILURE);
}

static int	openfile(char *const name, t_type const type)
{
	int	fd;

	fd = -1;
	if (name == NULL)
		return (fd);
	if (type == REDIN_TYPE)
		fd = open(name, O_RDONLY);
	else if (type == REDOUT_TYPE)
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND_TYPE)
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		g_exit_status = 1;
		errorfile(name, strerror(errno));
	}
	return (fd);
}

static int	checkfilename(t_env *env, t_files *iter)
{
	char	**args;

	if (iter == NULL || iter->name == NULL)
		return (EXIT_FAILURE);
	args = parse_expand(env, iter->name);
	if (args == NULL)
		return (errorfile(iter->name, "ambiguous redirect"));
	if (args[1] != NULL)
		return (utils_freestrs(args), errorfile(iter->name,
				"ambiguous redirect"));
	iter->fd = openfile(args[0], iter->type);
	return (utils_freestrs(args), iter->fd == -1);
}

int	cmds_checkfiles(t_env *env, t_files *files)
{
	t_files	*iter;

	if (files == NULL)
		return (g_exit_status = EXIT_SUCCESS);
	iter = files_first(files);
	while (iter != NULL)
	{
		if (iter->type == HEREDOC_TYPE)
		{
			iter = iter->next;
			continue ;
		}
		if (checkfilename(env, iter) != EXIT_SUCCESS)
			return (g_exit_status = EXIT_FAILURE);
		iter = iter->next;
	}
	return (g_exit_status = EXIT_SUCCESS);
}
