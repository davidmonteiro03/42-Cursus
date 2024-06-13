/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:13:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/06/05 15:20:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int		file_desc;
	char	buf[1024];
	int		file_desc_in;
	ssize_t	bytes_read;

	file_desc = open("dup.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	file_desc_in = open("dup.txt", O_RDONLY);
	dup2(file_desc_in, STDIN_FILENO);
	dup(file_desc);
	printf("This will also be output to the file named dup.txt\n");
	bytes_read = read(STDIN_FILENO, buf, sizeof(buf));
	buf[bytes_read] = '\0';
	printf("%s", buf);
	close(file_desc);
	close(file_desc_in);
	return (0);
}
