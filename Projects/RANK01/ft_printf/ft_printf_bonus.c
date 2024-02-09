/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:49:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 13:18:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*ft_datanew(char c)
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

void	ft_printdata(void *content, int *ret)
{
	t_data	*tmp;

	tmp = (t_data *)content;
	ft_putchar(tmp->c, ret);
}

void	ft_printarg(t_list *arg, int *ret)
{
	t_list	*tmp;

	tmp = arg;
	while (tmp)
	{
		ft_printdata(tmp->content, ret);
		tmp = tmp->next;
	}
}

void	ft_addchar(char c, t_list **list, bool pos)
{
	if (!pos)
		ft_lstadd_back(list, ft_lstnew(ft_datanew(c)));
	else
		ft_lstadd_front(list, ft_lstnew(ft_datanew(c)));
}

void	ft_addstr(char *str, t_list **list)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_addchar(*str++, list, false);
}

void	ft_addptr(void *ptr, t_list **list)
{
	char	*str;

	str = ft_converthex((size_t)ptr, ft_len((size_t)ptr));
	if (!str)
		return ;
	return (ft_addstr(str, list), free(str));
}

void	ft_addnbr(int num, t_list **list)
{
	if (num == -2147483648)
	{
		ft_addstr("-2147483648", list);
		return ;
	}
	if (num < 0)
	{
		ft_addchar('-', list, false);
		num = -num;
	}
	if (num > 9)
	{
		ft_addnbr(num / 10, list);
		ft_addnbr(num % 10, list);
	}
	else
		ft_addchar(num + '0', list, false);
}

void	ft_addnbr_base(unsigned int num, \
	unsigned int base, t_list **list, char c)
{
	char	*base_str;

	if (c == ft_tolower(c))
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (num > base - 1)
	{
		ft_addnbr_base(num / base, base, list, c);
		ft_addnbr_base(num % base, base, list, c);
	}
	else
		ft_addchar(base_str[num % base], list, false);
}

void	ft_format_bonus(char c, t_list **list, va_list args)
{
	void	*ptr;

	if (c == 'c')
		return (ft_addchar(va_arg(args, int), list, false));
	if (c == 's')
		return (ft_addstr(va_arg(args, char *), list));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (ft_addstr("(nil)", list));
		return (ft_addptr(ptr, list));
	}
	if (c == 'd' || c == 'i')
		return (ft_addnbr(va_arg(args, int), list));
	if (c == 'u')
		return (ft_addnbr_base(va_arg(args, unsigned int), 10, list, c));
	if (ft_tolower(c) == 'x')
		return (ft_addnbr_base(va_arg(args, unsigned int), 16, list, c));
	if (c == '%')
		return (ft_addchar('%', list, false));
}

char	ft_vtoc(void *content)
{
	t_data	*tmp;

	tmp = (t_data *)content;
	return (tmp->c);
}

char	*ft_ltoa(t_list *list)
{
	t_list	*tmp;
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_lstsize(list) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	tmp = list;
	while (tmp)
	{
		ret[i++] = ft_vtoc(tmp->content);
		tmp = tmp->next;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_hastag(char flag, t_list **arg, char *arg_str)
{
	if (flag == '#')
	{
	}
}

void	ft_addflags(char *frmt, t_list **arg)
{
	char	*arg_str;
	char	*tmp_frmt;
	char	flag1;

	tmp_frmt = frmt;
	arg_str = ft_ltoa(*arg);
	flag1 = '\0';
	if (ft_strchr("# +", *tmp_frmt))
		flag1 = *tmp_frmt++;
	if (flag1)
		ft_hastag(flag1, arg, arg_str);
	return (free(arg_str));
}

void	ft_check(const char *format, int *i, int *ret, va_list args)
{
	t_list	*arg;
	char	*frmt;

	frmt = ft_getformat(format, i);
	arg = NULL;
	ft_format_bonus(frmt[ft_strlen(frmt) - 1], &arg, args);
	ft_addflags(frmt, &arg);
	return (ft_printarg(arg, ret), free(frmt), ft_lstclear(&arg, free));
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
			ft_check(format, &i, &ret, args);
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
		ft_printf("\t%#0x %#x %#X %#.x %#.X %#5x %#5X %#-5x %#-5X %#.5x %#.5X %#-.5x %#-.5X", \
			0, 01, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("\n\t=====================================================================\n");
	int	cc_ret = \
		printf("\t%#0x %#x %#X %#.x %#.X %#5x %#5X %#-5x %#-5X %#.5x %#.5X %#-.5x %#-.5X", \
			0, 01, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	printf("\n\t=====================================================================\n");
	printf("\t\t\t   my_ret = %d | cc_ret = %d\n", my_ret, cc_ret);
	printf("\t=====================================================================\n\n");
	return (0);
}
