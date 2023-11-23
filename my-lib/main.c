/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 12:38:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib.h"

static void	ft_execute(t_test *t)
{
	t->u->nl = TRUE;
	t->u->i = 0;
	if (strcmp(t->a[1], "-n") == 0)
	{
		t->u->nl = FALSE;
		t->u->i = 1;
	}
	while (t->a[++t->u->i])
	{
		printf("%s", t->a[t->u->i]);
		if (t->a[t->u->i + 1])
			printf(" ");
	}
	if (t->u->nl)
		printf("\n");
}

static void	ft_analyse(t_test *t)
{
	t->a = ft_split(t->b, '\f');
	if (strcmp(t->a[0], "echo") != 0)
	{
		printf("bash: %s: command not found\n", t->a[0]);
		return (multiple_free("%b", t->a));
	}
	if (!t->a[1])
	{
		printf("\n");
		return (multiple_free("%b", t->a));
	}
	ft_execute(t);
	multiple_free("%b", t->a);
}

static void	ft_sendtotrash(t_test *t, int pro)
{
	if (pro == 1)
		multiple_free("%a%a%a%a%a", \
			t->b, t->c, t->u, t->l, t \
		);
	else if (pro == 0)
	{
		printf("You don't know how to use quotes, do you? 😑\n");
		multiple_free("%a%a%a%a", \
			t->c, t->u, t->l, t \
		);
	}
}

static int	ft_quotes(t_test *t)
{
	t->u->i = -1;
	t->c->s = FALSE;
	t->c->c = 0;
	while (t->l[++t->u->i])
	{
		if (!t->c->s && (t->l[t->u->i] == '\"' || \
			t->l[t->u->i] == '\''))
		{
			t->c->s = TRUE;
			t->c->c = t->l[t->u->i];
			continue ;
		}
		if (t->c->s && t->l[t->u->i] == t->c->c)
		{
			t->c->s = FALSE;
			t->c->c = 0;
			continue ;
		}
	}
	return (t->c->s);
}

int	main(void)
{
	t_test	*t;

	t = (t_test *)malloc(sizeof(t_test));
	t->l = readline("command $ ");
	if (!t->l)
		return (free(t), 0);
	t->u = (t_utils *)malloc(sizeof(t_utils));
	t->c = (t_check *)malloc(sizeof(t_check));
	if (ft_quotes(t))
		return (ft_sendtotrash(t, FALSE), 0);
	t->l = buildfree(t->l, " ", &ft_strtrim);
	t->u->i = -1;
	t->u->l = ft_mnstrlen(t);
	t->b = (char *)malloc(sizeof(char) * t->u->l + 1);
	t->b[t->u->l] = '\0';
	t->t_i = 0;
	t->u->i = -1;
	ft_strbuild(t);
	if (!t->b || !*t->b)
		return (ft_sendtotrash(t, TRUE), 0);
	ft_analyse(t);
	ft_sendtotrash(t, TRUE);
	return (0);
}
