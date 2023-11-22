/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 11:56:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib.h"

static void	ft_tmpbuild(t_test *t)
{
	size_t	len;

	len = 0;
	t->utils->tmp_3 = getenv(t->utils->tmp_2);
	while (t->utils->tmp_3[len])
		t->buf[t->tmp_i++] = t->utils->tmp_3[len++];
}

static void	ft_spbuild(t_test *t)
{
	t->utils->tmp = ft_substr(t->line, t->utils->j, t->utils->i - t->utils->j);
	t->utils->tmp_i = -1;
	while (t->utils->tmp[++t->utils->tmp_i])
	{
		if (t->utils->tmp[t->utils->tmp_i] == '$' && \
			ft_isalnum(t->utils->tmp[t->utils->tmp_i + 1]))
		{
			t->utils->tmp_j = t->utils->tmp_i + 1;
			while (t->utils->tmp[t->utils->tmp_i + 1] && \
				ft_isalnum(t->utils->tmp[t->utils->tmp_i + 1]))
				t->utils->tmp_i++;
			t->utils->tmp_2 = ft_substr(t->utils->tmp, t->utils->tmp_j, \
				t->utils->tmp_i - t->utils->tmp_j + 1);
			if (getenv(t->utils->tmp_2))
				ft_tmpbuild(t);
			free(t->utils->tmp_2);
			continue ;
		}
		t->buf[t->tmp_i++] = t->utils->tmp[t->utils->tmp_i];
	}
	free(t->utils->tmp);
}

static void	ft_opbuild(t_test *t, int op)
{
	if (op == 1)
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\'')
			t->buf[t->tmp_i++] = t->line[t->utils->i];
	else if (op == 2)
	{
		t->utils->j = t->utils->i + 1;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\"')
			;
		ft_spbuild(t);
	}
	else if (op == 3)
	{
		t->utils->j = t->utils->i;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != ' ' && \
			t->line[t->utils->i] != '\'' && t->line[t->utils->i] != '\"')
			;
		ft_spbuild(t);
		t->utils->i--;
	}
}

void	ft_strbuild(t_test *t)
{
	while (t->line[++t->utils->i])
	{
		if (t->line[t->utils->i] == '\'')
		{
			ft_opbuild(t, 1);
			continue ;
		}
		if (t->line[t->utils->i] == '\"')
		{
			ft_opbuild(t, 2);
			continue ;
		}
		if (t->line[t->utils->i] == ' ' && t->line[t->utils->i - 1] != ' ')
			t->buf[t->tmp_i++] = '\n';
		else if (t->line[t->utils->i] != ' ')
			ft_opbuild(t, 3);
	}
}
