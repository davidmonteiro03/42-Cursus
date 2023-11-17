/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:34:00 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/17 12:30:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		file_desc;
	int		copy_desc;
	char	buf[1024];

	file_desc = open("dup.txt", O_CREAT | O_RDWR | O_TRUNC);
	if (file_desc < 0)
		printf("Error opening the file\n");
	copy_desc = dup(file_desc);
	write(copy_desc, "This will be output to the file named dup.txt\n", 46);
	write(file_desc, "This will also be output to the file named dup.txt\n", \
		51);
	while (read(file_desc, buf, sizeof(buf)) > 0)
		printf("%s\n", buf);
	return (0);
}
