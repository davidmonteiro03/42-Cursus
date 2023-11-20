/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:59 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 12:44:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	error(char *error, char *arg)
{
	while (*error)
		write(2, error++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec(char **args, char **env, int i, int tmp)
{
	args[i] = NULL;
	dup2(tmp, STDIN_FILENO);
	close(tmp);
	execve(args[0], args, env);
	return (error("error: cannot execute ", args[0]));
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd[2];
	int	tmp;

	(void)ac;
	i = 0;
	tmp = dup(STDIN_FILENO);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (!av[i] || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (exec(av, env, i, tmp))
					return (1);
			}
			else
			{
				close(tmp);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (exec(av, env, i, tmp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp);
				tmp = fd[0];
			}
		}
	}
	close(tmp);
	return (0);
}
