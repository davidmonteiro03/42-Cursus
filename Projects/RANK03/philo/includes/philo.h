/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 13:20:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# define FORK "has taken a fork 🍴"
# define EAT "is eating 🍝"
# define THINK "is thinking 💭"
# define SLEEP "is sleeping 💤"
# define DIED "died 💀"

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_th;

struct					s_inf;

typedef struct s_ph
{
	int				meal_count;
	int				ph_id;
	long			lm;
	t_mutex			*lf;
	t_mutex			*rf;
	struct s_inf	*inf;
}t_ph;

typedef struct s_inf
{
	int		num_ph;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_meals_ph;
	long	time_start;
	t_ph	*ph;
	t_mutex	*f;
	t_th	*th;
	t_mutex	*action_lock;
}t_inf;

/* ************************************************************************** */
/*                                    CHECK                                   */
/* ************************************************************************** */

int		ph_atoi(const char *str);
bool	check_args(int ac, char **av);

/* ************************************************************************** */
/*                                    CLEAN                                   */
/* ************************************************************************** */

int		clean_inf(t_inf **inf, bool join);

/* ************************************************************************** */
/*                                   DISPLAY                                  */
/* ************************************************************************** */

void	start(void);
void	end(void);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

int		error(char *error);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		init_inf(t_inf **inf, int ac, char **av);

/* ************************************************************************** */
/*                                   ROUTINE                                  */
/* ************************************************************************** */

void	thinking(t_ph *ph);
void	sleeping(t_ph *ph);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

long	gettime(void);
void	status(t_ph *ph, char *status);

#endif
