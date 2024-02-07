/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:13:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/07 18:57:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_data
{
	char	c;
}t_data;

// main function
int		ft_printf(const char *format, ...);

// utils
char	*ft_converthex(size_t num, size_t size);
size_t	ft_len(size_t n);

// print
void	ft_format(char c, int *len, va_list args);
void	ft_putchar(char c, int *len);
void	ft_putnbr_base(unsigned int num, unsigned int base, int *len, char c);
void	ft_putnbr(int num, int *len);
void	ft_putptr(void *ptr, int *len);
void	ft_putstr(char *str, int *len);

#endif
