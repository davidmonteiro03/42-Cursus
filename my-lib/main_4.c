/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:41:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 13:02:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_4.h"

int	count_print_strs(char **strs, int i, int print)
{
	while (strs[++i])
		if (print)
			printf("%s\n", strs[i]);
	return (i);
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

int	read_dir_args(t_global *global, char **strs, int i, int total)
{
	global->old_args = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	global->old_args[count_print_strs(strs, -1, 0)] = NULL;
	global->new_args = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	global->new_args[count_print_strs(strs, -1, 0)] = NULL;
	while (strs[++i])
	{
		global->old_args[i] = (char **)malloc(sizeof(char *) * \
			(read_dir(strs[i], 0) + 1));
		global->old_args[i][read_dir(strs[i], 0)] = NULL;
		construct_args(strs[i], 0, &global->old_args[i]);
		total += count_print_strs(global->old_args[i], -1, 0);
		global->new_args[i] = new_args(global->old_args[i], \
			count_print_strs(global->old_args[i], -1, 0));
		sort_strs(&global->old_args[i], global->new_args[i], -1);
		count_print_strs(global->old_args[i], -1, 1);
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_global	*global;

	global = (t_global *)malloc(sizeof(t_global));
	if (!global)
		return (0);
	global->line = readline("wildcard (final) $ ");
	if (!global->line)
		return (free(global), 0);
	if (!*global->line)
		return (free(global->line), free(global), 0);
	global->input_args = ft_split(global->line, ' ');
	if (!global->input_args)
		return (free(global->line), free(global), 0);
	if (!*global->input_args)
		return (free(global->line), free(global->input_args), free(global), 0);
	read_dir_args(global, global->input_args, -1, 0);
	multiple_free("%c%c%b%a%a", global->new_args, global->old_args, \
		global->input_args, global->line, global);
	return ((void)ac, (void)av, 0);
}
