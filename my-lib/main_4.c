/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:41:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 14:07:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_4.h"

int	read_dir_args(t_global *global, char **strs, int i, int total)
{
	global->old_args = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	global->old_args[count_print_strs(strs, -1, 0)] = NULL;
	global->new_args = (char ***)malloc(sizeof(char **) * \
		(count_print_strs(strs, -1, 0) + 1));
	global->new_args[count_print_strs(strs, -1, 0)] = NULL;
	while (strs[++i])
	{
		global->old_args[i] = (char **)malloc(sizeof(char *) * \
			(read_dir(strs[i], 0) + 1));
		global->old_args[i][read_dir(strs[i], 0)] = NULL;
		construct_args(strs[i], 0, &global->old_args[i]);
		total += count_print_strs(global->old_args[i], -1, 0);
		global->new_args[i] = new_args(global->old_args[i], \
			count_print_strs(global->old_args[i], -1, 0));
		sort_strs(&global->old_args[i], global->new_args[i], -1);
	}
	return (total);
}

void	execute(char *command, char **args, char **envp)
{
	if (!fork())
	{
		execve(command, args, envp);
		printf("%s: command not found\n", args[0]);
		exit(0);
	}
	else
		wait(NULL);
}

int	execute_loop(t_global *global, char **envp)
{
	global->line = readline("wildcard (final) $ ");
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
	execute(global->command, global->exec_args, envp);
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
	while (execute_loop(global, envp))
		;
	rl_clear_history();
	printf("exit\n");
	return ((void)argc, (void)argv, free(global), 0);
}
