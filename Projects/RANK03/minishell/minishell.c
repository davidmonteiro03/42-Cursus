/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 19:13:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	free_line(t_mini *mini)
{
	if (mini->line)
		free(mini->line);
	free_input(mini->input);
	mini->input = init_input();
}

int	is_valid(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!(line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
			return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	*mini;

	init_mini(envp);
	mini = get_mini(NULL);
	while (1)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		mini->line = readline("MS-DOS> ");
		if (mini->line == NULL)
			ft_exit();
		if (ft_strcmp(mini->line, "") && !is_valid(mini->line))
		{
			if (!parser())
				pipe_exec(mini);
			add_history(mini->line);
			if (mini->line)
				free_line(mini);
		}
		else
			free_line(mini);
	}
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
