/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:39:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 08:20:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include "colors.h"
# include <readline/readline.h>
# include <readline/history.h>

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void	usage(void);
void	error(void);

/* ************************************************************************** */
/*                                    FREE                                    */
/* ************************************************************************** */

void	multiple_free(const char *format, ...);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

char	*ft_jointfree_1(char *s1, char *s2);
char	*ft_jointfree_2(char *s1, char *s2);
char	*ft_jointfree_all(char *s1, char *s2);

#endif
