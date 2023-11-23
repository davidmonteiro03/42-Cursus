/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 12:31:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib.h"

static size_t	ft_tmpstrlen(t_test *t)
{
	t->u->len = 0;
	t->u->t_3 = getenv(t->u->t_2);
	while (t->u->t_3[t->u->len])
		t->u->len++;
	return (t->u->len);
}

static int	ft_ststrlen(t_test *t)
{
	if (t->u->t_1[t->u->t_i + 1] == '?')
	{
		t->u->t_i++;
		t->u->t_i_f = 0;
		t->u->t_4 = ft_itoa(t->c->s);
		while (t->u->t_4[t->u->t_i_f])
			t->u->t_i_f++;
		t->u->l += t->u->t_i_f;
		return (free(t->u->t_4), 1);
	}
	return (0);
}

static size_t	ft_spstrlen(t_test *t)
{
	t->u->len = 0;
	t->u->t_1 = ft_substr(t->l, t->u->j, t->u->i - t->u->j);
	t->u->t_i = -1;
	while (t->u->t_1[++t->u->t_i])
	{
		if (t->u->t_1[t->u->t_i] == '$' && (ft_isalnum(t->u->t_1[t->u->t_i \
			+ 1]) || t->u->t_1[t->u->t_i + 1] == '?'))
		{
			if (ft_ststrlen(t))
				continue ;
			t->u->t_j = t->u->t_i + 1;
			while (t->u->t_1[t->u->t_i + 1] && \
				ft_isalnum(t->u->t_1[t->u->t_i + 1]))
				t->u->t_i++;
			t->u->t_2 = ft_substr(t->u->t_1, t->u->t_j, \
				t->u->t_i - t->u->t_j + 1);
			if (getenv(t->u->t_2))
				t->u->len += ft_tmpstrlen(t);
			free(t->u->t_2);
			continue ;
		}
		t->u->len++;
	}
	return (free(t->u->t_1), t->u->len);
}

static size_t	ft_opstrlen(t_test *t, int op)
{
	t->u->len = 0;
	if (op == 1)
		while (t->l[++t->u->i] && t->l[t->u->i] != '\'')
			t->u->len++;
	else if (op == 2)
	{
		t->u->j = t->u->i + 1;
		while (t->l[++t->u->i] && t->l[t->u->i] != '\"')
			;
		t->u->len += ft_spstrlen(t);
	}
	else if (op == 3)
	{
		t->u->j = t->u->i;
		while (t->l[++t->u->i] && t->l[t->u->i] != ' ' && \
			t->l[t->u->i] != '\'' && t->l[t->u->i] != '\"')
			;
		t->u->len += ft_spstrlen(t);
		t->u->i--;
	}
	return (t->u->len);
}

size_t	ft_mnstrlen(t_test *t)
{
	t->u->len = 0;
	while (t->l[++t->u->i])
	{
		if (t->l[t->u->i] == '\'')
		{
			t->u->len += ft_opstrlen(t, 1);
			continue ;
		}
		if (t->l[t->u->i] == '\"')
		{
			t->u->len += ft_opstrlen(t, 2);
			continue ;
		}
		if (ft_strchr(" \t\n", t->l[t->u->i]) && \
			!ft_strchr(" \t\n", t->l[t->u->i - 1]))
			t->u->len++;
		else if (t->l[t->u->i] != ' ')
			t->u->len += ft_opstrlen(t, 3);
	}
	return (t->u->len);
}
