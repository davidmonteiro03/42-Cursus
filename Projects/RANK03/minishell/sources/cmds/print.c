/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:47:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/18 13:16:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	spamchars(int const fd, size_t const len, char const c, \
	bool const newline)
{
	if (fd == -1 || len == 0 || c == '\0')
		return ;
	ft_putchar_fd(c, fd);
	if (len - 1 == 0 && newline == true)
		ft_putchar_fd('\n', fd);
	spamchars(fd, len - 1, c, newline);
}

static void	showargs(int fd, char *const *args)
{
	size_t	i;

	display_fprintf(fd, "args <%p>\n", args);
	if (args != NULL)
	{
		i = 0;
		while (args[i] != NULL)
		{
			ft_putstr_fd("> ", fd);
			ft_putendl_fd(args[i++], fd);
		}
	}
}

void	cmds_print(int fd, t_cmds *const cmds)
{
	t_cmds	*iter;
	int		len;

	if (fd == -1 || cmds == NULL)
		return ;
	iter = cmds_first(cmds);
	while (iter != NULL)
	{
		len = display_fprintf(fd, "======== cmd <%p> ========\n", iter);
		display_fprintf(fd, "files\n", iter, iter->files);
		files_print(fd, 1, iter->files);
		showargs(fd, iter->args);
		iter = iter->next;
	}
	spamchars(fd, len - 1, '=', true);
}
