/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:23:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 15:13:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	ft_revstr(char **str, size_t start, size_t end)
{
	size_t	fix_pos;
	size_t	i;
	char	tmp;

	fix_pos = (start + end) / 2;
	i = 0;
	while (start < fix_pos)
	{
		tmp = (*str)[start];
		(*str)[start] = (*str)[end - i - 1];
		(*str)[end - i - 1] = tmp;
		start++;
		i++;
	}
}

void	rev_wstr(char *str)
{
	size_t	i;
	size_t	start;
	size_t	end;

	ft_revstr(&str, 0, ft_strlen(str));
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		end = i;
		ft_revstr(&str, start, end);
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	write(1, str, ft_strlen(str));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
