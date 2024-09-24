/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:52:30 by preis-ne          #+#    #+#             */
/*   Updated: 2024/07/07 14:55:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FILES
#  define FILES 1024
# endif

/********** Functions  */

/*LIBFT*/

int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
size_t				ft_strlen(const char *ptr);
void				*ft_memset(void *ptr, int i, size_t n);
void				ft_bzero(void *ptr, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
int					ft_toupper(int i);
int					ft_tolower(int i);
char				*ft_strchr(const char *ptr, int i);
char				*ft_strrchr(const char *ptr, int i);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *ptr, int i, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *ptr);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*GET NEXT LINE*/

size_t				ft_search(char *str, int n);
char				*get_next_line(int fd);

/*PRINTF*/

/*manipulations_strings_two*/
void				ft_putchar_len(int c, int *len);
int					ft_uppercheck(const char *str, int *i);
char				*ft_basecheck(int *upper);
void				ft_searchupper(const char *str, int *i, int *upper);
void				ft_puthex_pre(const char *str, int *i, int *len, int hex);
/*manipulations_strings*/
void				ft_putstr_lennil(int *len);
void				ft_putstr_lenszeros(int *len, int *strsize, int *printsize);
void				ft_putstr_lenspaces(int *len, int *strsize, int *printsize);
void				ft_putstr_len(char *c, int *len, int *size);
void				ft_putstr_lennull(int *len);
/*manipulations_numbers_two*/
int					ft_nbrlen_unsigned(unsigned int nbr, int base);
int					ft_nbrlen(unsigned long long int nbr, int base);
int					ft_nbrlen_ten(int nbr, int base);
int					ft_figures(int *d);
int					ft_digits(const char *str, int *i);
/*manipulations_numbers*/
int					ft_number(const char *str, int *i, int *j);
void				ft_putnbr(long n, int *len);
void				ft_putnbr_unsigned(unsigned int n, int *len);
void				ft_putnbr_base_x(unsigned int nb, int *len, char *base);
void				ft_putnbr_base(unsigned long long int nb, int *len,
						char *base);
/*di_manipulations*/
void				ft_checksignal(const char *str, int *i, int nb, int *len);
int					ft_sps(const char *str, int *i, int n);
void				ft_cutsizenumber(int *cutsize, int number, int *len);
void				ft_strsizenumber(const char *str, int *i, int number,
						int *len);
/*u_manipulations*/
void				ft_checksignal_u(const char *str, int *i, int nb, int *len);
int					ft_sps_u(const char *str, int *i, int n);
void				ft_cutsizenumber_u(int *cutsize, int number, int *len);
void				ft_strsizenumber_u(const char *str, int *i, int number,
						int *len);
/*xX_manipulations*/
void				ft_cutsizenumber_xx(const char *str, va_list args, int *i,
						int *len);
void				ft_strsizenumber_xx(const char *str, int *i, int number,
						int *len);
/*flags*/
int					ft_minus(const char *str, int *i);
int					ft_space(const char *str, int *i);
int					ft_plus(const char *str, int *i);
int					ft_sharp(const char *str, int *i);
int					ft_zero(const char *str, int *i);
/*cases*/
void				ft_case_c(const char *str, va_list args, int *i, int *len);
void				ft_case_s(const char *str, va_list args, int *i, int *len);
void				ft_case_p(const char *str, va_list args, int *i, int *len);
void				ft_case_di(const char *str, va_list args, int *i, int *len);
void				ft_case_u(const char *str, va_list args, int *i, int *len);
void				ft_case_xx(const char *str, va_list args, int *i, int *len);
void				ft_case_percent(const char *str, int *i, int *len);
/*printf*/
int					ft_precision(const char *str, int *i);
int					ft_width(const char *str, int *i);
void				ft_screening(const char *str, va_list args, int *i,
						int *len);
int					ft_printf(const char *s, ...);

#endif
