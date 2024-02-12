/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:49:18 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 21:00:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_list	*so_long_get_file_content(char *file)
{
	t_list	*list;
	t_list	*node;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (so_long_error_file(file), NULL);
	list = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		node = ft_lstnew(ft_strtrim(tmp, "\n"));
		if (!node)
		{
			free(node);
			ft_lstclear(&list, free);
			return (close(fd), so_long_error(ERROR_MALLOC), NULL);
		}
		ft_lstadd_back(&list, node);
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (close(fd), list);
}
