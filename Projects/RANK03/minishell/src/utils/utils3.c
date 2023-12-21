/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 06:46:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_space(char *line, int *i)
{
	while ((line[*i] && line[*i] == ' ') || (line[*i] && line[*i] == '\t'))
		*i += 1;
}

int	skip(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	return (i);
}
