/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wild_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:47:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 19:59:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
			&& wild_match(sd->d_name, pattern))
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
			&& wild_match(sd->d_name, pattern))
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

t_wild	read_dir_args(char **strs, int i)
{
	t_wild	wild;
	char	***new_args;

	wild.total = 0;
	wild.sstrs = (char ***)malloc(sizeof(char **) * (strs_size(strs) + 1));
	wild.sstrs[(strs_size(strs))] = NULL;
	new_args = (char ***)malloc(sizeof(char **) * (strs_size(strs) + 1));
	new_args[(strs_size(strs))] = NULL;
	while (strs[++i])
	{
		wild.sstrs[i] = (char **)malloc(sizeof(char *) * \
			(read_dir(strs[i], 0) + 1));
		wild.sstrs[i][read_dir(strs[i], 0)] = NULL;
		construct_args(strs[i], 0, &wild.sstrs[i]);
		wild.total += strs_size(wild.sstrs[i]);
		new_args[i] = ft_new_args(wild.sstrs[i], strs_size(wild.sstrs[i]));
		sort_strs(&wild.sstrs[i], new_args[i], -1);
	}
	free_arrays(new_args);
	return (wild);
}

char	**wild_args(char **strs)
{
	char	**wild_args;
	int		i;
	int		j;
	int		k;
	t_wild	wild;

	if (!strs)
		return (NULL);
	wild = read_dir_args(strs, -1);
	wild_args = (char **)malloc(sizeof(char *) * (wild.total + 1));
	k = 0;
	i = -1;
	while (wild.sstrs[++i])
	{
		j = -1;
		while (wild.sstrs[i][++j])
			wild_args[k++] = ft_strdup(wild.sstrs[i][j]);
	}
	wild_args[k] = NULL;
	free_arrays(wild.sstrs);
	free_split(strs);
	return (wild_args);
}
