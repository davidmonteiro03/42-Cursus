/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:39:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 13:53:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_4.h"

int	read_dir(char *pattern, int count)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		st;

	dir = opendir(".");
	if (!dir)
		return (count);
	while (1)
	{
		sd = readdir(dir);
		if (!sd)
			break ;
		if (!stat(sd->d_name, &st) && sd->d_name[0] != '.' \
			&& wildcmp(sd->d_name, pattern))
			count++;
	}
	if (!count)
		return (closedir(dir), 1);
	return (closedir(dir), count);
}

int	construct_args(char *pattern, int count, char ***temp)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		st;

	dir = opendir(".");
	if (!dir)
		return (count);
	while (1)
	{
		sd = readdir(dir);
		if (!sd)
			break ;
		if (!stat(sd->d_name, &st) && sd->d_name[0] != '.' \
			&& wildcmp(sd->d_name, pattern))
			(*temp)[count++] = ft_strdup(sd->d_name);
	}
	if (!count)
	{
		(*temp)[0] = ft_strdup(pattern);
		(*temp)[1] = NULL;
		return (closedir(dir), 1);
	}
	(*temp)[count] = NULL;
	return (closedir(dir), count);
}

char	**new_args(char **src, int size)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		dest[i] = new_args_util(src[i]);
	dest[size] = NULL;
	return (dest);
}

void	olg_args_to_exec_args(t_global *global, char ***strs, int i, int k)
{
	int	j;

	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			global->exec_args[k++] = ft_strdup(strs[i][j]);
	}
	global->exec_args[k] = NULL;
}
