/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:58 by dcaetano         ###   ########.fr       */
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

struct	s_inf;

typedef struct s_ph
{
	int				n;
	long			lm;
	struct s_inf	*inf;
}t_ph;

typedef struct s_inf
{
	int		np;
	int		ttd;
	int		tte;
	int		tts;
	int		notepme;
	long	st;
	bool	die;
	t_ph	*ph;
}t_inf;

/* ************************************************************************** */
/*                                   CHECKS                                   */
/* ************************************************************************** */

int		ph_atoi(const char *nptr);
void	check_number(char *str);
void	check_args(int ac, char **av);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void	error_message(void);
void	check_num_args(int ac, char **av);
void	error_usage(int ac, char **av);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

void	init_inf(t_inf *inf, int ac, char **av);
void	init_philos(t_inf *inf);

/* ************************************************************************** */
/*                                 USAGE UTILS                                */
/* ************************************************************************** */

void	usage_1(char **av);
void	usage_2(char **av);
void	usage_3(char **av);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

void	status(t_ph *ph, char *info);
long	get_time(void);

#endif
