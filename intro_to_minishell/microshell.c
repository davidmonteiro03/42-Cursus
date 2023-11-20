/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:59 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 12:20:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write, dup, close, execve
#include <string.h> // strcmp
#include <sys/wait.h> // waitpid

int	error(char *error, char *arg) // function to print an error message
{
	while (*error)
		write(2, error++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	exec(char **args, char **env, int i, int tmp) // function to execute a command
{
	args[i] = NULL; // set the next argument to NULL
	dup2(tmp, STDIN_FILENO); // redirect the standard input to the tmp file descriptor
	close(tmp); // close the tmp file descriptor
	execve(args[0], args, env); // execute the command
	return (error("error: cannot execute ", args[0])); // if the command fails, return 1
}

int	main(int ac, char **av, char **env)
{
	int	i; // variable to iterate through the arguments
	int	fd[2]; // pipe file descriptor
	int	tmp; // tmp file descriptor

	(void)ac; // unused
	i = 0; // initialize i to 0
	tmp = dup(STDIN_FILENO); // save the standard input file descriptor
	while (av[i] && av[i + 1]) // iterate through the arguments
	{
		av = &av[i + 1]; // set the arguments to the next command
		i = 0; // reset i to 0
		while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0) // iterate through the arguments until we find a ; or |
			i++;
		if (strcmp(av[0], "cd") == 0) // if the command is cd
		{
			if (i != 2) // if the number of arguments is not 2
				error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0) // if the directory does not exist
				error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (!av[i] || strcmp(av[i], ";") == 0)) // if the command is not cd and the next command is ; or the end of the arguments
		{
			if (fork() == 0) // fork the process
			{
				if (exec(av, env, i, tmp)) // execute the command
					return (1); // if the command fails, return 1
			}
			else
			{
				close(tmp); // close the tmp file descriptor
				while (waitpid(-1, NULL, WUNTRACED) != -1) // wait for the child process to finish
					;
				tmp = dup(STDIN_FILENO); // restore the standard input file descriptor
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0) // if the command is not cd and the next command is |
		{
			pipe(fd); // create a pipe
			if (fork() == 0) // fork the process
			{
				dup2(fd[1], STDOUT_FILENO); // redirect the standard output to the pipe
				close(fd[0]); // close the read end of the pipe
				close(fd[1]); // close the write end of the pipe
				if (exec(av, env, i, tmp)) // execute the command
					return (1); // if the command fails, return 1
			}
			else // if the command is not cd and the next command is |
			{
				close(fd[1]); // close the write end of the pipe
				close(tmp); // close the tmp file descriptor
				tmp = fd[0]; // set the tmp file descriptor to the read end of the pipe
			}
		}
	}
	close(tmp); // close the tmp file descriptor
	return (0);
}
