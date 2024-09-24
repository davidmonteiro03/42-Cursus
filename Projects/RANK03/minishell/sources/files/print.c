/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:47:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	spamchars(int const fd, size_t const len, char const c,
		bool const newline)
{
	if (fd == -1 || len == 0 || c == '\0')
		return ;
	ft_putchar_fd(c, fd);
	if (len - 1 == 0 && newline == true)
		ft_putchar_fd('\n', fd);
	spamchars(fd, len - 1, c, newline);
}

static void	readfile(int fd, int fdout, size_t tabs)
{
	char	*line;

	if (fd == -1 || fdout == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		spamchars(fdout, tabs + 1, '\t', false);
		display_fprintf(fdout, "> %s", line);
		free(line);
		line = get_next_line(fd);
	}
}

static void	showfile(int fd, size_t tabs, t_files *const iter)
{
	if (fd == -1 || iter == NULL)
		return ;
	spamchars(fd, tabs, '\t', false);
	display_fprintf(fd, "fd  : %d\n", iter->fd);
	readfile(iter->fd, fd, tabs);
	spamchars(fd, tabs, '\t', false);
	display_fprintf(fd, "type: %d\n", iter->type);
	spamchars(fd, tabs, '\t', false);
	display_fprintf(fd, "name: %s\n", iter->name);
}

void	files_print(int fd, size_t tabs, t_files *const files)
{
	t_files	*iter;
	int		len;

	if (fd == -1 || files == NULL)
		return ;
	iter = files_first(files);
	while (iter != NULL)
	{
		spamchars(fd, tabs, '\t', false);
		if (tabs < 1)
			len = display_fprintf(fd, "======== file <%p> ========\n", iter);
		else
			len = display_fprintf(fd, "-------- file <%p> --------\n", iter);
		showfile(fd, tabs, iter);
		iter = iter->next;
	}
	spamchars(fd, tabs, '\t', false);
	if (tabs < 1)
		spamchars(fd, len - 1, '=', true);
	else
		spamchars(fd, len - 1, '-', true);
}
