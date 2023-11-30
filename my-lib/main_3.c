/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:17:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 14:38:04 by dcaetano         ###   ########.fr       */
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
	gb->pd = fork();
	if (!gb->pd)
	{
		execve(gb->cm, gb->ag, ev);
		gb->tp = strs_rng(gb->ag, 0, gb->tb[0], -1);
		if (dsp_sz(gb->tp, -1, FALSE) == 1)
			dsp_err(gb->tp[0]);
		else
			dsp_err(get_arg(gb, gb->tp[0], \
				gb->tp[dsp_sz(gb->tp, -1, FALSE) - 1]));
		multiple_free("%b", gb->tp);
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
	gb->cm = buildfree(ft_strdup("/bin/"), ft_strdup(gb->as[0]), &ft_strjoin);
	if (!gb->cm)
		return (multiple_free("%b%a", gb->as, gb->ln), 1);
	if (!ft_strncmp(gb->cm, "/bin/exit\0", 10))
		return (multiple_free("%b%a%a", gb->as, gb->cm, gb->ln), 0);
	wild_get(gb);
	if (!gb->ag)
		return (multiple_free("%b%a%a%a", gb->as, gb->ln, gb->cm, gb->tb), 1);
	if (!*gb->ag)
		return (multiple_free("%b%a%a%a%a", gb->as, gb->ag, gb->tb, gb->cm, \
			gb->ln), 1);
	ft_exec(gb, ev);
	return (multiple_free("%b%b%a%a%a", gb->as, gb->ag, gb->tb, gb->cm, \
		gb->ln), 1);
}

t_gb	*init_gb(void)
{
	t_gb	*gb;

	gb = (t_gb *)malloc(sizeof(t_gb));
	if (!gb)
		return (NULL);
	gb->ln = NULL;
	gb->dr = NULL;
	gb->pt = NULL;
	gb->cm = NULL;
	gb->as = NULL;
	gb->ai = 0;
	gb->ag = NULL;
	gb->tb = NULL;
	gb->tp = NULL;
	return (gb);
}

int	main(int ac, char **av, char **ev)
{
	t_gb	*gb;

	gb = init_gb();
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
