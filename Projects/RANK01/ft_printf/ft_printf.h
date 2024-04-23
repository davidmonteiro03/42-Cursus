/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:05:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 10:27:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

// ------ main function ------ //
int		ft_printf(const char *format, ...); // ft_printf

// ----- format functions ---- //
void	ft_putchar(const char c, int *ret);
void	ft_putstr(const char *str, int *ret);
void	ft_putptr(const void *ptr, int *ret);
void	ft_putnbr(int nbr, int *ret);

// ----- utils functions ----- //
void	ft_format(const char *format, va_list args, int *ret);

#endif
