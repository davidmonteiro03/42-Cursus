/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:23:39 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	split_inputs(t_mini *mini)
{
	int		i;
	int		j;
	t_input	*tmp;

	i = 0;
	j = 0;
	tmp = mini->input;
	while (mini->line[i])
	{
		if (mini->line[i] == '\"' || mini->line[i] == '\'')
			i += skip(&mini->line[i + 1], mini->line[i]) + 2;
		else if (mini->line[i] == '|' && get_exit_code(0, 0) != -1)
		{
			tmp->line = malloc(i - j + 1);
			ft_strlcpy(tmp->line, &mini->line[j], i - j + 1);
			tmp->next = init_input();
			tmp = tmp->next;
			j = ++i;
		}
		else
			i++;
	}
	tmp->line = malloc(i - j + 1);
	ft_strlcpy(tmp->line, &mini->line[j], i - j + 1);
	tmp->next = NULL;
}

int	parser(void)
{
	t_mini	*mini;

	mini = get_mini(NULL);
	if (check_line(mini->line))
		return (1);
	while (1)
	{
		if (check_heardoc(mini, -1))
			return (1);
		if (check_line(mini->line))
			return (1);
		if (mini->line[ft_strlen(mini->line) - 1] != '|')
			break ;
		else
			if (call_heardoc_pipe(mini))
				return (1);
	}
	return (split_inputs(mini), 0);
}
