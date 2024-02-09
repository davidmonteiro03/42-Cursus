/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:13:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:31:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

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

// bonus
typedef struct s_data
{
	char	c;
}t_data;

void	ft_addchar_bonus(char c, t_list **list, bool pos);
void	ft_addflags_bonus(char *frmt, t_list **arg);
void	ft_addnbr_base_bonus(unsigned int num, \
	unsigned int base, t_list **list, char c);
void	ft_addnbr_bonus(int num, t_list **list);
void	ft_addptr_bonus(void *ptr, t_list **list);
void	ft_addstr_bonus(char *str, t_list **list);
void	ft_check_bonus(const char *format, int *i, int *ret, va_list args);
void	ft_check_flag_bonus(char *frmt, size_t *i, \
	char *arg_str, t_list **arg);
void	ft_check_tab_bonus(char *frmt, size_t i, char *arg_str, t_list **arg);
void	ft_checkdec_bonus(char *frmt, char fill, t_list **arg, int num);
void	ft_checkhex_bonus(t_list **arg);
void	ft_checkint_bonus(t_list **arg);
t_data	*ft_datanew_bonus(char c);
void	ft_findbug_bonus(t_list **arg, char c);
void	ft_fixbughex_bonus(t_list **arg, t_list *node1, t_list *node2);
void	ft_fixbugint_bonus(t_list **arg, t_list *node);
void	ft_format_bonus(char c, t_list **list, va_list args);
char	*ft_getformat_bonus(const char *format, int *i);
char	*ft_ltoa_bonus(t_list *list);
void	ft_printarg_bonus(t_list *arg, int *ret);
void	ft_printdata_bonus(void *content, int *ret);
void	ft_removenode_bonus(t_list **arg, t_list *node);
void	ft_truncate_bonus(t_list **arg, int trunc);
char	ft_vtoc_bonus(void *content);

#endif
