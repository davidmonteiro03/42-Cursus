/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:16:56 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 15:39:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

static void	simplefree(void *pnt)
{
	if (!pnt)
		return ;
	free(pnt);
}

static void	free_pnts(void **pnts)
{
	int	i;

	if (!pnts)
		return ;
	i = -1;
	while (pnts[++i])
		free(pnts[i]);
	free(pnts);
}

static void	free_ppnts(void ***ppnts)
{
	int	i;

	if (!ppnts)
		return ;
	i = -1;
	while (ppnts[++i])
		free_pnts(ppnts[i]);
	free(ppnts);
}

static void	type_free(va_list args, const char format)
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
