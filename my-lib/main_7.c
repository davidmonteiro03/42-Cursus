/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:34:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 09:03:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_7.h"

char	**ft_strs_create(char *str)
{
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * 2);
	strs[0] = ft_strdup(str);
	strs[1] = NULL;
	return (strs);
}

char	**ft_add_str(char **strs, char *str, int i)
{
	static char	**new_strs;

	if (!str)
		return (strs);
	if (!strs)
	{
		if (!new_strs)
			new_strs = ft_strs_create(str);
		return (new_strs);
	}
	if (!*strs)
	{
		new_strs = ft_strs_create(str);
		return (free(strs), new_strs);
	}
	i = -1;
	while (strs[++i])
		;
	new_strs = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (strs[++i])
		new_strs[i] = ft_strdup(strs[i]);
	new_strs[i] = ft_strdup(str);
	new_strs[i + 1] = NULL;
	return (multiple_free("%b", strs), new_strs);
}

void	ft_print_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		printf("%s\n", strs[i]);
}

int	main(void)
{
	char	**strs;

	strs = ft_add_str(NULL, NULL, -1);
	strs = ft_add_str(strs, NULL, -1);
	strs = ft_add_str(strs, "World", -1);
	strs = ft_add_str(strs, "Hello", -1);
	strs = ft_add_str(strs, "World", -1);
	ft_print_strs(strs);
	multiple_free("%b", strs);
	return (0);
}
