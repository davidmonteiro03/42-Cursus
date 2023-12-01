/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:41:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 18:43:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_4.h"

int	g_status = 0;

void	new_prompt(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		printf("\n");
		rl_redisplay();
	}
}

void	presentation(t_global *global)
{
	if (g_status == 0)
		global->line = readline(BCYN "shell " BGRN "$" RESET " ");
	else
		global->line = readline(BCYN "shell " BRED "$" RESET " ");
}

void	execute(t_global *global, char **envp)
{
	global->pid = fork();
	if (!global->pid)
	{
		execve(global->command, global->exec_args, envp);
		printf("%s: command not found\n", global->exec_args[0]);
		exit(127);
	}
	else
	{
		waitpid(global->pid, &global->status, 0);
		if (WIFEXITED(global->status))
			g_status = WEXITSTATUS(global->status);
		else
			g_status = 1;
	}
}

int	execute_loop(t_global *global, char **envp)
{
	presentation(global);
	if (!global->line)
		return (0);
	if (!*global->line)
		return (free(global->line), 1);
	global->input_args = ft_split(global->line, ' ');
	if (!global->input_args)
		return (free(global->line), 1);
	if (!*global->input_args)
		return (free(global->line), free(global->input_args), 1);
	global->total = read_dir_args(global, global->input_args, -1, 0);
	global->exec_args = (char **)malloc(sizeof(char *) * (global->total + 1));
	add_history(global->line);
	olg_args_to_exec_args(global, global->old_args, -1, 0);
	if (!ft_strncmp(global->exec_args[0], "exit\0", 5))
		return (multiple_free("%c%c%b%b%a", global->new_args, \
			global->old_args, global->exec_args, global->input_args, \
			global->line), 0);
	global->command = buildfree(ft_strdup("/bin/"), \
		ft_strdup(global->exec_args[0]), &ft_strjoin);
	execute(global, envp);
	multiple_free("%c%c%b%b%a%a", global->new_args, global->old_args, \
		global->exec_args, global->input_args, global->line, global->command);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_global	*global;

	global = (t_global *)malloc(sizeof(t_global));
	if (!global)
		return (0);
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
	while (execute_loop(global, envp))
		;
	rl_clear_history();
	printf("exit\n");
	return ((void)argc, (void)argv, free(global), g_status);
}
