/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:13:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_red(char line)
{
	if (line == '<' || line == '>')
		return (0);
	return (1);
}

int	check_heardoc(t_mini *mini, int i)
{
	char	c;
	char	*tmp;

	while (mini->line[++i])
	{
		if (mini->line[i] == '\"' || mini->line[i] == '\'')
		{
			c = mini->line[i++];
			i += skip(&mini->line[i], c);
			if (!mini->line[i])
			{
				if (call_heardoc_quotes(&mini->line, c))
					return (1);
				else
				{
					i = -1;
					continue ;
				}
			}
		}
	}
	tmp = mini->line;
	mini->line = ft_strtrim(mini->line, " ");
	return (free(tmp), 0);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '|')
		return (ft_fprintf(2, "bash: syntax error near \
unexpected token `|'\n"), 1);
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			i += skip(&line[i + 1], line[i]) + 1;
			if (!line[i])
				continue ;
		}
		else if ((!check_red(line[i]) || line[i] == '|')
			&& !(line[i] == '|' && line[i + 1] == '|'))
		{
			if (check_special(&line[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
