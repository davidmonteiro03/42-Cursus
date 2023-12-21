/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:31:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redirects(t_mini *mini)
{
	int		i;
	int		flag;
	char	**tmp;

	tmp = mini->input->args;
	i = -1;
	flag = 0;
	while (tmp[++i])
	{
		if (tmp[i][0] == '>' || tmp[i][0] == '<')
		{
			if (flag)
			{
				ft_fprintf(2,
					"bash: syntax error near unexpected token `%s'", tmp[i]);
				return (1);
			}
			flag = 1;
		}
		else
			flag = 0;
	}
	return (0);
}

char	*trim_quotes(char *s)
{
	if (!s)
		return (NULL);
	if (s[0] == '\"')
		return (ft_strtrim(s, "\""));
	else if (s[0] == '\'')
		return (ft_strtrim(s, "\'"));
	return (ft_strdup(s));
}

char	**trim_args(char **args)
{
	int		i;
	char	**new_args;

	i = 0;
	while (args[i])
		i++;
	if (i == 0)
		return (NULL);
	new_args = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (args[++i])
		new_args[i] = ft_strdup(args[i]);
	new_args[i] = NULL;
	return (new_args);
}

static int	organize_args(t_input *input)
{
	char	*tmp;
	int		i;

	tmp = input->line;
	input->line = ft_strtrim(input->line, " ");
	free(tmp);
	i = -1;
	while (input->line[++i])
	{
		if (input->line[i] == '\'' || input->line[i] == '\"')
			i += skip(&input->line[i + 1], input->line[i]) + 1;
		if (input->line[i] == '>' || input->line[i] == '<')
		{
			if (input->heardoc && input->line[i] == '<'
				&& input->line[i + 1] == '<')
				free(input->heardoc);
			if (handle_redirect(input, i))
				return (1);
		}
	}
	return (0);
}

int	exec(t_input *input)
{
	char	*tmp;
	int		i;
	int		std_in;
	int		std_out;

	std_in = dup(0);
	std_out = dup(1);
	if (organize_args(input))
		return (dup2(std_in, 0), dup2(std_out, 1), 1);
	tmp = input->line;
	input->line = ft_strtrim(input->line, " ");
	free(tmp);
	i = exec2(input);
	dup2(std_in, 0);
	dup2(std_out, 1);
	return (i);
}
