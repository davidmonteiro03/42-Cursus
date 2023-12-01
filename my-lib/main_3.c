/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:17:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 00:10:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_3.h"

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

void	ft_exec(t_gb *gb, char **ev)
{
	char	*tmp;

	gb->pd = fork();
	if (!gb->pd)
	{
		gb->tp = new_args(gb->ag, gb->ai);
		tmp = gb->ag[0];
		sort_strs(gb, gb->tp);
		multiple_free("%b", gb->tp);
		execve(gb->cm, gb->ag, ev);
		if (stat(tmp, &gb->st))
			dsp_err(tmp);
		else
			dsp_err(gb->ag[0]);
		exit(127);
	}
	else
	{
		waitpid(gb->pd, &gb->ss, 0);
		if (WIFEXITED(gb->ss))
			g_status = WEXITSTATUS(gb->ss);
		else
			g_status = 1;
	}
}

int	exec(t_gb *gb, char **ev)
{
	gb->ln = readline(gb->in);
	if (!gb->ln)
		return (0);
	if (!*gb->ln)
		return (free(gb->ln), 1);
	gb->as = ft_split(gb->ln, ' ');
	if (!gb->as)
		return (free(gb->ln), 1);
	if (!*gb->as)
		return (free(gb->ln), free(gb->as), 1);
	add_history(gb->ln);
	wild_get(gb);
	if (!gb->ag)
		return (multiple_free("%b%a%a", gb->as, gb->ln, gb->tb), 1);
	if (!*gb->ag)
		return (multiple_free("%b%a%a%a", gb->as, gb->ag, gb->tb, gb->ln), 1);
	gb->cm = buildfree(ft_strdup("/bin/"), ft_strdup(gb->ag[0]), &ft_strjoin);
	if (!gb->cm)
		return (multiple_free("%b%b%a%a", gb->as, gb->ag, gb->ln, gb->tb), 1);
	if (!ft_strncmp(gb->cm, "/bin/exit\0", 10))
		return (multiple_free("%b%b%a%a%a", gb->as, gb->ag, gb->cm, \
			gb->ln, gb->tb), 0);
	ft_exec(gb, ev);
	return (multiple_free("%b%b%a%a%a", gb->as, gb->ag, gb->tb, gb->cm, \
		gb->ln), 1);
}

int	main(int ac, char **av, char **ev)
{
	t_gb	*gb;

	gb = (t_gb *)malloc(sizeof(t_gb));
	if (!gb)
		return (0);
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		if (g_status == 0)
			gb->in = ft_strdup(BCYN "shell " BGRN "$" RESET " ");
		else
			gb->in = ft_strdup(BCYN "shell " BRED "$" RESET " ");
		if (!exec(gb, ev))
			break ;
		free(gb->in);
	}
	rl_clear_history();
	printf("exit\n");
	return ((void)ac, (void)av, free(gb->in), free(gb), g_status);
}
