/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:23:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 12:31:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

int	get_strs_size(char **strs, int i)
{
	while (strs[++i])
		;
	return (i);
}

void	print_strs(char **strs, int i)
{
	while (strs[++i])
		printf("%s\n", strs[i]);
}

char	**strs_rng(char **strs, int bgn, int end, int i)
{
	char	**rng;

	rng = (char **)malloc(sizeof(char *) * (end - bgn + 1));
	if (!rng)
		return (NULL);
	rng[end - bgn] = NULL;
	while (bgn < end && strs[bgn])
		rng[++i] = ft_strdup(strs[bgn++]);
	return (rng);
}

char	*get_arg(t_gb *gb, char *first, char *last)
{
	if (stat(first, &gb->st))
		return (first);
	if (S_ISDIR(gb->st.st_mode))
		return (first);
	return (last);
}
