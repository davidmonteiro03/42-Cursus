/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:16:56 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 17:12:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	simplefree(void *pnt)
{
	if (!pnt)
		return ;
	free(pnt);
}

void	free_pnts(void **pnts)
{
	int	i;

	if (!pnts)
		return ;
	i = -1;
	while (pnts[++i])
		simplefree(pnts[i]);
	simplefree(pnts);
}

void	free_ppnts(void ***ppnts)
{
	int	i;

	if (!ppnts)
		return ;
	i = -1;
	while (ppnts[++i])
		free_pnts(ppnts[i]);
	simplefree(ppnts);
}

void	type_free(va_list args, const char format)
{
	if (format == 'a')
		simplefree(va_arg(args, void *));
	else if (format == 'b')
		free_pnts(va_arg(args, void **));
	else if (format == 'c')
		free_ppnts(va_arg(args, void ***));
}

void	multiple_free(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			if (ft_strchr("abc", *(format + i + 1)))
				type_free(args, *(format + i + 1));
			i++;
		}
		i++;
	}
	va_end(args);
}
