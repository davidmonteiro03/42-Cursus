/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:49:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/08 21:56:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*ft_initdata(char c)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->c = c;
	return (data);
}

char	*ft_getformat(const char *format, int *i)
{
	int		start;
	int		end;

	start = ++(*i);
	while (format[*i] && !ft_strchr("cspdiuxX%%", format[*i]))
		(*i)++;
	end = *i + 1;
	return (ft_substr(format, start, end - start));
}

void	ft_format_bonus(const char *format, int *i, int *ret, va_list args)
{
	char	*frmt;

	frmt = ft_getformat(format, i);
	free(frmt);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;
	int		i;

	ret = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_format_bonus(format, &i, &ret, args);
		else
			ft_putchar(format[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}

int	main(void)
{
	printf("\n\t=====================================================================\n");
	int	my_ret = \
		ft_printf("\t%#x %#x %#X %#.x %#.X %#5x %#5X %#-5x %#-5X %#.5x %#.5X %#-.5x %#-.5X", \
			0, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("\n\t=====================================================================\n");
	int	cc_ret = \
		printf("\t%#x %#x %#X %#.x %#.X %#5x %#5X %#-5x %#-5X %#.5x %#.5X %#-.5x %#-.5X", \
			0, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("\n\t=====================================================================\n");
	printf("\t\t\t   my_ret = %d | cc_ret = %d\n", my_ret, cc_ret);
	printf("\t=====================================================================\n\n");
	return (0);
}
