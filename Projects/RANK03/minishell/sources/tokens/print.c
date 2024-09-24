/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 08:07:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_tabs(int fd, size_t tabs)
{
	if (tabs == 0)
		return ;
	display_fprintf(fd, "\t");
	print_tabs(fd, tabs - 1);
}

void	tokens_print(int fd, size_t tabs, t_tokens *const tokens)
{
	t_tokens	*iter;

	if (fd == -1 || tokens == NULL)
		return ;
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		print_tabs(fd, tabs);
		display_fprintf(fd, "token <%p> | ", iter);
		display_fprintf(fd, "type: %d, value: %s\n", iter->type, iter->value);
		iter = iter->next;
	}
}
