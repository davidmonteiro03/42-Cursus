/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 09:32:47 by dcaetano         ###   ########.fr       */
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

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mutex;
typedef time_t			t_time;

struct					s_inf;

typedef struct s_ph
{
	int				ph_id;
	int				meal_count;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	struct s_inf	*inf;
}t_ph;

typedef struct s_inf
{
	int		num_ph;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_time_meals_ph;
	t_ph	*ph;
	t_mutex	*forks;
	t_th	*th;
}t_inf;

/* ************************************************************************** */
/*                                    CLEAN                                   */
/* ************************************************************************** */

void	clean_all(t_inf *inf, int code);

/* ************************************************************************** */
/*                                    CHECK                                   */
/* ************************************************************************** */

int		ph_atoi(const char *str);
bool	check_args(int ac, char **av);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

int		error(char *error);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		init_forks(t_inf *inf);
int		init_philos(t_inf *inf);
int		init_inf(t_inf *inf, int ac, char **av);

#endif
