/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 12:53:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdbool.h>

/* ************************************************************************** */
/*                                   CHECKS                                   */
/* ************************************************************************** */

long int	ph_atol(const char *nptr);
void		check_number(char *str);
void		check_args(int ac, char **av);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void		error_message(void);
void		check_num_args(int ac, char **av);
void		error_usage(int ac, char **av);

/* ************************************************************************** */
/*                                 USAGE UTILS                                */
/* ************************************************************************** */

void		usage_std(void);
void		usage_1(char **av);
void		usage_2(char **av);
void		usage_3(char **av);

#endif
