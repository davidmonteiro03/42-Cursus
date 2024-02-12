/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 20:39:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	so_long_check_file_content(char *file)
{
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (so_long_error_file(file), exit(1));
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), so_long_error(ERROR_EMPTY), exit(1));
	while (tmp)
	{
		if (!ft_strchr(tmp, '\n'))
			return (free(tmp), close(fd), \
				so_long_error(ERROR_CONTENT), exit(1));
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	so_long_check_args(argc, argv);
	so_long_check_file_content(argv[1]);
	return ((void)argc, (void)argv, 0);
}
