/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 17:50:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_help
{
	int	fd;
	int	i;
	int	len;
}		t_help;

// ft_printf
int		ft_printf(const char *format, ...);
// mandatory
void	ft_format(const char *format, va_list args, t_help *help);
void	ft_putchar(char c, t_help *help);
void	ft_putnbr(int nbr, t_help *help);
void	ft_putnbr_base(unsigned int nbr, unsigned int base, int uppercase,
			t_help *help);
void	ft_putptr(void *ptr, t_help *help);
void	ft_putstr(char *str, t_help *help);
// bonus
void	ft_format_bonus(const char *format, va_list args, t_help *help);

#endif // !FT_PRINTF_H
