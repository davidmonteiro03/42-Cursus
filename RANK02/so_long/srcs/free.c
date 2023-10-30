/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:16:56 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 19:31:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_strings(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

void	type_free(va_list args, const char format)
{
	if (format == 'p')
		free(va_arg(args, void *));
	else if (format == 'a')
		free_strings(va_arg(args, char **));
}

void	multiple_free(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			if (ft_strchr("pa", *(format + i + 1)))
				type_free(args, *(format + i + 1));
			i++;
		}
		i++;
	}
	va_end(args);
}
