/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:34:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 19:21:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_6.h"

typedef struct s_wild
{
	char	***sstrs;
	int		total;
}t_wild;

int	ft_strscmp(const char *s1, const char *s2)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = -1;
	while (aux_s1[++i] || aux_s2[i])
	{
		if (aux_s1[i] != aux_s2[i])
		{
			if (!ft_isalnum(aux_s1[i]) && ft_isalnum(aux_s2[i]))
				return (1);
			if (!ft_isalnum(aux_s2[i]) && ft_isalnum(aux_s1[i]))
				return (-1);
			return (aux_s1[i] - aux_s2[i]);
		}
	}
	return (0);
}

char	*ft_strlow(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

void	sort_strs(char ***old, char **new, int i)
{
	int		j;
	char	*tmp;

	while ((*old)[++i])
	{
		j = i;
		while ((*old)[++j])
		{
			if (ft_strscmp(ft_strlow(new[i]), ft_strlow(new[j])) > 0)
			{
				tmp = (*old)[i];
				(*old)[i] = (*old)[j];
				(*old)[j] = tmp;
				tmp = new[i];
				new[i] = new[j];
				new[j] = tmp;
			}
		}
	}
}

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

int	strs_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
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

char	*new_args_util(const char *src)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	i = -1;
	j = 0;
	while (src[++i])
		if (src[i] != '_')
			dest[j++] = src[i];
	dest[j] = '\0';
	return (dest);
}

char	**ft_new_args(char **src, int size)
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

void	display_strs(char **strs, int i)
{
	while (strs[++i])
	{
		printf("%s", strs[i]);
		if (strs[i + 1])
			printf(" => ");
	}
	printf("\n");
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
	multiple_free("%c", new_args);
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
	multiple_free("%c", wild.sstrs);
	return (wild_args);
}

int	main(int argc, char **argv)
{
	char	**args;

	(void)argc;
	args = wild_args(argv + 1);
	display_strs(args, -1);
	multiple_free("%b", args);
	return (0);
}
