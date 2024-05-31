/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:05:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 12:58:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

// ------ main function ------ //
int		ft_printf(const char *format, ...); // ft_printf

// ----- format functions ---- //
void	ft_putchar(const char c, int *ret); // ft_putchar
void	ft_putstr(const char *str, int *ret); // ft_putstr
void	ft_putptr(const void *ptr, int *ret); // ft_putptr
void	ft_putnbr(int nbr, int *ret); // ft_putnbr
void	ft_putnbr_base(unsigned int nbr, unsigned int base, \
	int *ret, int (*f)(int)); // ft_putnbr_base

// ----- utils functions ----- //
void	ft_format(const char *format, va_list args, int *ret); // ft_format

#endif
