/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:43:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*read_file(int fd)
{
	char	*str;
	char	*c;

	str = ft_strdup("");
	c = malloc(2);
	while (read(fd, c, 1))
	{
		c[1] = '\0';
		str = ft_joint_free(str, c);
		c = malloc(2);
	}
	free(c);
	close(fd);
	return (str);
}

void	send_to_file(char *str, char *path, int append)
{
	int	fd;

	if (!path)
	{
		ft_fprintf(1, "Argumentos inválidos\n");
		return ;
	}
	if (append)
		fd = open(path, O_APPEND);
	else
		fd = open(path, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0777);
	if (fd < 0)
	{
		ft_fprintf(1, "Não foi possível abrir o arquivo\n");
		return ;
	}
	ft_fprintf(fd, "%s", str);
	close(fd);
}
