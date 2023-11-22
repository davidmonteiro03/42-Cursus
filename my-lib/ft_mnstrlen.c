/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 09:19:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static size_t	ft_tmpstrlen(t_test *t)
{
	size_t	len;

	len = 0;
	t->utils->tmp_3 = getenv(t->utils->tmp_2);
	while (t->utils->tmp_3[len])
		len++;
	return (len);
}

static size_t	ft_spstrlen(t_test *t)
{
	size_t	len;

	len = 0;
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
				len += ft_tmpstrlen(t);
			free(t->utils->tmp_2);
			continue ;
		}
		len++;
	}
	free(t->utils->tmp);
	return (len);
}

static size_t	ft_opstrlen(t_test *t, int op)
{
	size_t	len;

	len = 0;
	if (op == 1)
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\'')
			len++;
	else if (op == 2)
	{
		t->utils->j = t->utils->i + 1;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != '\"')
			;
		len += ft_spstrlen(t);
	}
	else if (op == 3)
	{
		t->utils->j = t->utils->i;
		while (t->line[++t->utils->i] && t->line[t->utils->i] != ' ' && \
			t->line[t->utils->i] != '\'' && t->line[t->utils->i] != '\"')
			;
		len += ft_spstrlen(t);
		t->utils->i--;
	}
	return (len);
}

size_t	ft_mnstrlen(t_test *t)
{
	size_t	len;

	len = 0;
	while (t->line[++t->utils->i])
	{
		if (t->line[t->utils->i] == '\'')
		{
			len += ft_opstrlen(t, 1);
			continue ;
		}
		if (t->line[t->utils->i] == '\"')
		{
			len += ft_opstrlen(t, 2);
			continue ;
		}
		if (t->line[t->utils->i] == ' ' && t->line[t->utils->i - 1] != ' ')
			len++;
		else if (t->line[t->utils->i] != ' ')
			len += ft_opstrlen(t, 3);
	}
	return (len);
}
