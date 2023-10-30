/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepareargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:50:30 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/27 07:29:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_jointfree(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

int	getlen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	freechars(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

char	**jointsplit(int len, char **av)
{
	char	**strs;
	char	*tmp;
	int		i;

	tmp = ft_strdup("");
	i = -1;
	while (++i < len)
	{
		tmp = ft_jointfree(tmp, av[i]);
		tmp = ft_jointfree(tmp, " ");
	}
	strs = ft_split(tmp, ' ');
	free(tmp);
	return (strs);
}

void	validargs(char **strs)
{
	if (!*strs)
	{
		if (strs)
			free(strs);
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
