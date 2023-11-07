/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 19:40:33 by dcaetano         ###   ########.fr       */
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

struct	s_info;

typedef struct s_philo
{
	int				n;
	int				ec;
	long			lm;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	struct s_info	*info;
	pthread_t		id;
}t_philo;

typedef struct s_info
{
	int				np;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	long			st;
	bool			die;
	pthread_t		*th;
	pthread_mutex_t	*f;
	t_philo			*ph;
}t_info;

/* ************************************************************************** */
/*                                 CHECK ARGS                                 */
/* ************************************************************************** */

int		philo_atoi(const char *nptr);
void	check_atoi(char *str);
void	check_args(int ac, char **av);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void	error(void);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

void	init_forks(t_info *info);
void	init_philos(t_info *info);
void	init_info(t_info *info, int ac, char **av);

/* ************************************************************************** */
/*                                 PHILO UTILS                                */
/* ************************************************************************** */

long	get_time(void);
void	philo_waitms(int ms);
void	display_status(t_philo *philo, char *action);

#endif
