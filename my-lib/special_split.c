/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:06:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 09:17:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

void	special_split(t_test *t)
{
	while (t->buf[++t->utils->i])
	{
		if (t->buf[t->utils->i] == '\"')
		{
			while (t->buf[++t->utils->i] && t->buf[t->utils->i] != '\"')
				printf("%c", t->buf[t->utils->i]);
			continue ;
		}
		if (t->buf[t->utils->i] == '\'')
		{
			while (t->buf[++t->utils->i] && t->buf[t->utils->i] != '\'')
				printf("%c", t->buf[t->utils->i]);
			continue ;
		}
		printf("%c", t->buf[t->utils->i]);
	}
}
