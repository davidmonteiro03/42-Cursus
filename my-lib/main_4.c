/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:41:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 12:45:15 by dcaetano         ###   ########.fr       */
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

int	read_dir_args(char **strs, int i, int total)
{
	char	***old;
	char	***new;

	old = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	old[count_print_strs(strs, -1, 0)] = NULL;
	new = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	new[count_print_strs(strs, -1, 0)] = NULL;
	while (strs[++i])
	{
		old[i] = (char **)malloc(sizeof(char *) * \
			(read_dir(strs[i], 0) + 1));
		old[i][read_dir(strs[i], 0)] = NULL;
		construct_args(strs[i], 0, &old[i]);
		printf("\nold[%d]:\n\n", i);
		total += count_print_strs(old[i], -1, 1);
		new[i] = new_args(old[i], \
			count_print_strs(old[i], -1, 0));
		printf("\nnew[%d]:\n\n", i);
		count_print_strs(new[i], -1, 1);
	}
	multiple_free("%c", old);
	multiple_free("%c", new);
	return (i);
}

int	main(int ac, char **av, char **ev)
{
	char	*line;
	char	**args1;

	line = readline("wildcard (final) $ ");
	if (!line)
		return (0);
	if (!*line)
		return (free(line), 0);
	args1 = ft_split(line, ' ');
	if (!args1)
		return (free(line), 0);
	if (!*args1)
		return (free(line), free(args1), 0);
	read_dir_args(args1, -1, 0);
	multiple_free("%b%a", args1, line);
	(void)ev;
	return ((void)ac, (void)av, 0);
}
