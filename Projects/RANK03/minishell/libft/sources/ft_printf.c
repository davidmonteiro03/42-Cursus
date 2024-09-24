/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:00:36 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_precision(const char *str, int *i)
{
	int	n;
	int	j;

	j = 0;
	n = 0;
	while (str[*i + j] != '.' && str[*i + j] != '\0'
		&& ft_isalpha(str[*i + j]) != 1)
		j++;
	if (ft_isalpha(str [*i + j]) == 1)
		return (-3);
	if (str [*i + j] == '\0')
		return (-2);
	if (ft_isdigit(str[*i + j + 1]) != 1)
		return (-1);
	j++;
	n = ft_number(str, i, &j);
	return (n);
}

int	ft_width(const char *str, int *i)
{
	int	n;
	int	j;

	j = 0;
	while (str[*i + j] != '\0' && str[*i + j] != '.'
		&& ft_isalpha(str[*i + j]) != 1)
		j++;
	if (ft_isdigit(str[*i + j - 1]) == 0)
		return (-1);
	while (ft_isdigit(str[*i + j - 1]) == 1)
		j--;
	n = ft_number(str, i, &j);
	return (n);
}

void	ft_screening(const char *str, va_list args, int *i, int *len)
{
	int	j;

	j = 1;
	while (ft_strchr("-0# +.", str[*i + j]) != 0
		|| ft_isdigit(str[*i + j]))
		j++;
	if (ft_strchr("c", str[*i + j]) != 0)
		ft_case_c(str, args, i, len);
	else if (ft_strchr("s", str[*i + j]) != 0)
		ft_case_s(str, args, i, len);
	else if (ft_strchr("p", str[*i + j]) != 0)
		ft_case_p(str, args, i, len);
	else if (ft_strchr("d", str[*i + j]) != 0
		||ft_strchr("i", str[*i + j]) != 0)
		ft_case_di(str, args, i, len);
	else if (ft_strchr("u", str[*i + j]) != 0)
		ft_case_u(str, args, i, len);
	else if (ft_strchr("x", str[*i + j]) != 0
		||ft_strchr("X", str[*i + j]) != 0)
		ft_case_xx(str, args, i, len);
	else if (ft_strchr("%", str[*i + j]) != 0)
		ft_case_percent(str, i, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%-0# +.", str[i + 1]) != 0
				|| ft_isdigit(str[i + 1]))
				ft_screening(str, args, &i, &len);
			else
				ft_putchar_len('%', &len);
		}
		else
			ft_putchar_len(str[i], &len);
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{
 	char	a;
 	char	b;
 	int	c;
 	int	d;

 	a = 0;
 	b = 0;
//	a = ft_printf("%s\n", 0);
//	b = printf("%s\n", 0);
//	printf("%d\n%d\n", a, b);
//	printf("\n");
 	c = 0;
 	d = 0;
 	c = ft_printf("%-%%-86p%-75.65X%--%%0%" 
 	,(void*)2090071458243268605lu,2822691287u);
 	d = printf("%-%%-86p%-75.65X%--%%0%" ,(
 	void*)2090071458243268605lu,2822691287u);
 	printf("%d\n%d\n", c, d);


}//minus, zero, precision, sharp in Xx. 
*/
