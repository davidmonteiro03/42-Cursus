/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 15:02:26 by dcaetano         ###   ########.fr       */
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

typedef pthread_mutex_t	t_f;
typedef pthread_t		t_id;

struct					t_inf;

typedef struct s_ph
{
	int				n;
	long			lm;
	t_f				*lf;
	t_f				*rf;
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
	t_f		*f;
	t_id	*id;
	t_ph	*ph;
}t_inf;

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
/*                                    INIT                                    */
/* ************************************************************************** */

void		init_forks(t_inf *inf);
void		init_philos(t_inf *inf);
void		init_inf(t_inf *inf, int ac, char **av);

/* ************************************************************************** */
/*                                   ROUTINE                                  */
/* ************************************************************************** */

void		lock_forks(t_ph *ph);
void		unlock_forks(t_ph *ph);

/* ************************************************************************** */
/*                                 USAGE UTILS                                */
/* ************************************************************************** */

void		usage_std(void);
void		usage_1(char **av);
void		usage_2(char **av);
void		usage_3(char **av);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

long		get_time(void);
void		status(t_ph *ph, char *status);
void		display_start(void);
void		display_end(void);

#endif
