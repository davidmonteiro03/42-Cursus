/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:00:36 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	display_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	t_tmp	tmp;

	va_start(args, str);
	tmp = (t_tmp){.i = -1, .len = 0, .fd = fd};
	while (str[++tmp.i])
	{
		if (str[tmp.i] == '%')
		{
			if (ft_strchr("cspdiuxX%-0# +.", str[tmp.i + 1]) != 0
				|| ft_isdigit(str[tmp.i + 1]))
				display_screening(str, args, &tmp);
			else
				display_putchar_len('%', &tmp);
		}
		else
			display_putchar_len(str[tmp.i], &tmp);
	}
	va_end(args);
	return (tmp.len);
}

int	display_precision(const char *str, t_tmp *tmp)
{
	int	n;
	int	j;

	j = 0;
	n = 0;
	while (str[tmp->i + j] != '.' && str[tmp->i + j] != '\0'
		&& ft_isalpha(str[tmp->i + j]) != 1)
		j++;
	if (ft_isalpha(str [tmp->i + j]) == 1)
		return (-3);
	if (str [tmp->i + j] == '\0')
		return (-2);
	if (ft_isdigit(str[tmp->i + j + 1]) != 1)
		return (-1);
	j++;
	n = display_number(str, tmp, &j);
	return (n);
}

void	display_screening(const char *str, va_list args, t_tmp *tmp)
{
	int	j;

	j = 1;
	while (ft_strchr("-0# +.", str[tmp->i + j]) != 0
		|| ft_isdigit(str[tmp->i + j]))
		j++;
	if (ft_strchr("c", str[tmp->i + j]) != 0)
		display_case_c(str, args, tmp);
	else if (ft_strchr("s", str[tmp->i + j]) != 0)
		display_case_s(str, args, tmp);
	else if (ft_strchr("p", str[tmp->i + j]) != 0)
		display_case_p(str, args, tmp);
	else if (ft_strchr("d", str[tmp->i + j]) != 0
		||ft_strchr("i", str[tmp->i + j]) != 0)
		display_case_di(str, args, tmp);
	else if (ft_strchr("u", str[tmp->i + j]) != 0)
		display_case_u(str, args, tmp);
	else if (ft_strchr("x", str[tmp->i + j]) != 0
		||ft_strchr("X", str[tmp->i + j]) != 0)
		display_case_xx(str, args, tmp);
	else if (ft_strchr("%", str[tmp->i + j]) != 0)
		display_case_percent(str, tmp);
}

int	display_width(const char *str, t_tmp *tmp)
{
	int	n;
	int	j;

	j = 0;
	while (str[tmp->i + j] != '\0' && str[tmp->i + j] != '.'
		&& ft_isalpha(str[tmp->i + j]) != 1)
		j++;
	if (ft_isdigit(str[tmp->i + j - 1]) == 0)
		return (-1);
	while (ft_isdigit(str[tmp->i + j - 1]) == 1)
		j--;
	n = display_number(str, tmp, &j);
	return (n);
}
