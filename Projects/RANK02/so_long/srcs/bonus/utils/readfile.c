/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:12:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:12:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

t_list	*ft_filetolist(int fd)
{
	t_list	*ret;
	t_list	*tmp_node;
	char	*line;

	if (fd == -1)
		return (NULL);
	ret = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp_node = ft_lstnew(ft_strdup(line));
		free(line);
		ft_lstadd_back(&ret, tmp_node);
		line = get_next_line(fd);
	}
	return (ret);
}

char	**ft_readfile(int fd)
{
	char	**ret;
	t_list	*tmp;
	t_list	*head;
	int		i;

	ret = NULL;
	tmp = ft_filetolist(fd);
	if (tmp == NULL)
		return (NULL);
	head = tmp;
	ret = (char **)malloc(sizeof(char *) * (ft_lstsize(tmp) + 1));
	if (ret == NULL)
		return (ft_lstclear(&head, &free), NULL);
	i = 0;
	while (tmp != NULL)
	{
		ret[i++] = ft_strtrim(tmp->content, "\n");
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ft_lstclear(&head, &free), ret);
}
