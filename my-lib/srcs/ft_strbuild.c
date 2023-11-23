/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 12:32:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib.h"

static void	ft_tmpbuild(t_test *t)
{
	size_t	len;

	len = 0;
	t->u->t_3 = getenv(t->u->t_2);
	while (t->u->t_3[len])
		t->b[t->t_i++] = t->u->t_3[len++];
}

static int	ft_stbuild(t_test *t)
{
	if (t->u->t_1[t->u->t_i + 1] == '?')
	{
		t->u->t_i++;
		t->u->t_i_f = 0;
		t->u->t_4 = ft_itoa(t->c->s);
		while (t->u->t_4[t->u->t_i_f])
			t->b[t->t_i++] = t->u->t_4[t->u->t_i_f++];
		return (free(t->u->t_4), 1);
	}
	return (0);
}

static void	ft_spbuild(t_test *t)
{
	t->u->t_1 = ft_substr(t->l, t->u->j, t->u->i - t->u->j);
	t->u->t_i = -1;
	while (t->u->t_1[++t->u->t_i])
	{
		if (t->u->t_1[t->u->t_i] == '$' && (ft_isalnum(t->u->t_1[t->u->t_i \
			+ 1]) || t->u->t_1[t->u->t_i + 1] == '?'))
		{
			if (ft_stbuild(t))
				continue ;
			t->u->t_j = t->u->t_i + 1;
			while (t->u->t_1[t->u->t_i + 1] && \
				ft_isalnum(t->u->t_1[t->u->t_i + 1]))
				t->u->t_i++;
			t->u->t_2 = ft_substr(t->u->t_1, t->u->t_j, \
				t->u->t_i - t->u->t_j + 1);
			if (getenv(t->u->t_2))
				ft_tmpbuild(t);
			free(t->u->t_2);
			continue ;
		}
		t->b[t->t_i++] = t->u->t_1[t->u->t_i];
	}
	free(t->u->t_1);
}

static void	ft_opbuild(t_test *t, int op)
{
	if (op == 1)
		while (t->l[++t->u->i] && t->l[t->u->i] != '\'')
			t->b[t->t_i++] = t->l[t->u->i];
	else if (op == 2)
	{
		t->u->j = t->u->i + 1;
		while (t->l[++t->u->i] && t->l[t->u->i] != '\"')
			;
		ft_spbuild(t);
	}
	else if (op == 3)
	{
		t->u->j = t->u->i;
		while (t->l[++t->u->i] && t->l[t->u->i] != ' ' && \
			t->l[t->u->i] != '\'' && t->l[t->u->i] != '\"')
			;
		ft_spbuild(t);
		t->u->i--;
	}
}

void	ft_strbuild(t_test *t)
{
	while (t->l[++t->u->i])
	{
		if (t->l[t->u->i] == '\'')
		{
			ft_opbuild(t, 1);
			continue ;
		}
		if (t->l[t->u->i] == '\"')
		{
			ft_opbuild(t, 2);
			continue ;
		}
		if (ft_strchr(" \t\n", t->l[t->u->i]) && \
			!ft_strchr(" \t\n", t->l[t->u->i - 1]))
			t->b[t->t_i++] = '\a';
		else if (t->l[t->u->i] != ' ')
			ft_opbuild(t, 3);
	}
}
