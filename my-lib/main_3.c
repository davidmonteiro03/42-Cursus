/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:17:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/29 15:19:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_3.h"

void	new_prompt(int sig)
{
	(void)sig;
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		printf("\n");
		rl_redisplay();
	}
}

int	exec(t_gb *gb, char **e)
{
	gb->ln = readline("wildcard $ ");
	if (!gb->ln)
		return (0);
	if (!*gb->ln)
		return (free(gb->ln), 0);
	gb->as = ft_split(gb->ln, ' ');
	if (!gb->as)
		return (free(gb->ln), 1);
	if (!*gb->as)
		return (free(gb->ln), free(gb->as), 1);
	gb->cm = buildfree(ft_strdup("/bin/"), ft_strdup(gb->as[0]), &ft_strjoin);
	if (!gb->cm)
		return (multiple_free("%b%a", gb->as, gb->ln), 1);
	if (!ft_strncmp(gb->cm, "exit\0", 5))
		return (multiple_free("%b%a%a", gb->as, gb->ln, gb->cm), 0);
	wild_get(gb);
	if (!gb->ag)
		return (multiple_free("%a%a%b", gb->ln, gb->cm, gb->as), 1);
	if (!*gb->ag)
		return (multiple_free("%a%a%b%a", gb->ln, gb->cm, gb->as, gb->ag), 1);
	if (!fork())
		execve(gb->cm, gb->ag, e);
	else
		wait(NULL);
	return (multiple_free("%a%a%b%b", gb->ln, gb->cm, gb->as, gb->ag), 1);
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
	gb->fg = 0;
	gb->ag = NULL;
	return (gb);
}

int	main(int ac, char **av, char **env)
{
	t_gb	*gb;

	gb = init_gb();
	if (!gb)
		return (0);
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
	while (exec(gb, env))
		;
	printf("exit\n");
	return ((void)ac, (void)av, free(gb), 0);
}
